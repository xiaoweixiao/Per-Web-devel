#ifndef __PROTOCOLUTIL_HPP__
#define __PROTOCOLUTIL_HPP__

#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <sstream>
#include <unordered_map>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/sendfile.h>
#include <sys/wait.h>
#include "log.hpp"

#define NOT_FOUND 404
#define OK 200
#define WEB_ROOT "wwwroot"
#define HOME_PAGE "index.html"

#define HTTP_VERSION "http/1.0"

//rq的suffix与rsp的ContentType的unordered_map对照表,unorder_map的初始化
std::unordered_map<std::string,std::string> suffix_map
{
    {".html","text/html"},
    {".htm","text/html"},
    {".css","text/css"},
    {".js","application/x-javascript"}
    
};
class ProtocolUtil{
    public:
        static void MakeKV(std::unordered_map<std::string,std::string> &kv_,std::string &str_)
        {
            std::size_t pos_ = str_.find(": ");
            if(std::string::npos == pos_)
            {
                return;
            }

            std::string k_ = str_.substr(0,pos_);
            std::string v_ = str_.substr(pos_+2);

            kv_.insert(make_pair(k_,v_));
        }
        static std::string IntToString(int code)
        {
            std::stringstream ss;
            ss << code;
            return ss.str();
        }
        static std::string CodetoDesc(int code)
        {
            switch(code)
            {
                case 200:
                    return "Ok";
                case 404:
                    return "Not Found";
                default:
                    return "UNkonw";
            }
        }
        static std::string SuffixToType(const std::string &suffix_)
        {
            return suffix_map[suffix_.c_str()];
        }
};
class Request{
    public:
        std::string rq_line;
        std::string rq_head;
        std::string blank;
        std::string rq_text;
    private:
        std::string method;
        std::string uri;
        std::string version;
        bool cgi;//POST GET(?)

        std::string path;
        std::string param;

        int resource_size;

        std::unordered_map<std::string,std::string> head_kv;
        int content_length;

        std::string resource_suffix;
    public:
        Request()
            :blank("\n")
             ,cgi(false)
             ,path(WEB_ROOT)
             ,resource_size(0)
             ,content_length(-1)
             ,resource_suffix(".html")
    {}

        std::string & GetParam()
        {
            return param;
        }

        int GetResourceSize()
        {
            return resource_size;
        }
        std::string GetSuffix()
        {
            return resource_suffix;
        }
        std::string &GetPath()
        {
            return path;
        }
        void RequestLineParse()
        {
            std::stringstream ss(rq_line);
            ss >> method >> uri >> version;
        }
        bool IsMethodLegal()
        {
            if(strcasecmp(method.c_str(),"GET") == 0)
            {
                return true;
            }else if(strcasecmp(method.c_str(),"POST") == 0)
            {
                cgi = true;
                return true;
            }
            return false;
        }
        void UriParse()
        {
            if(strcasecmp(method.c_str(),"GET") == 0)
            {
                std::size_t pos_ = uri.find('?');
                if(pos_ != std::string::npos)
                {
                    cgi = true;
                    path += uri.substr(0,pos_);//substr的第二个参数是截取的步长，
                    //下标为pos_的位置是‘？’截取到pos_之前，截取pos_个
                    param = uri.substr(pos_+1);
                }
            }else
            {
                path += uri;
            }
            if(path[path.size()-1] == '/')
            {
                path += HOME_PAGE;
            }
        }

        bool RequestHeadParse()
        {
            int start = 0;
            while(start < rq_head.size())
            {
                std::size_t pos_ = rq_head.find('\n',start);
                if(std::string::npos == pos_)
                {
                    break;
                }
                std::string sub_string_ = rq_head.substr(start,pos_ - start);
                if(!sub_string_.empty())
                {
                    ProtocolUtil::MakeKV(head_kv,sub_string_);
                }else
                {
                    break;
                }
                start = pos_ + 1;
            }
        }
        int GetContentLength()
        {
            std::string cl_ = head_kv["Content-Length"];
            if(!cl_.empty())
            {
                std::stringstream ss(cl_);
                ss >> content_length;
            }
            return content_length;
        }
        bool IsPathLegal()
        {
            struct stat st;
            if(stat(path.c_str(),&st)<0)//stat函数查看文件属性
            {
                LOG(WARNING,"path not found");
                return false;
            }

            if(S_ISDIR(st.st_mode))//stat函数中有解析S_ISDIR判断文件是否是目录
            {
                path += '/';
                path += HOME_PAGE;
            }
            else
            {
                //判断一下文件的user、group、other是否具有可执行权限，stat函数中有解析
                if((st.st_mode & S_IXUSR)||\
                        (st.st_mode & S_IXGRP)||\
                        (st.st_mode & S_IXOTH))
                {
                    cgi = true;
                }
            }
            resource_size = st.st_size;//资源长度
            std::size_t pos_ = path.rfind(".");
            if(std::string::npos == pos_)
                resource_suffix = path.substr(pos_);
            return true;
        }
        bool IsNeedRecvText()
        {
            if(strcasecmp(method.c_str(),"POST"))
            {
                return true;
            }
            return false;
        }
        bool IsCgi()
        {
            return cgi;
        }
        ~Request()
        {}
};

class Response{
    public:
        std::string rsp_line;
        std::string rsp_head;
        std::string blank;
        std::string rsp_text;
    public:
        int code;
        int fd;
    public:
        Response()
            :blank("\n")
             ,code(OK)
             ,fd(-1)
    {}

        void MakeStatusLine()
        {
            rsp_line = HTTP_VERSION;
            rsp_line += "";
            rsp_line += ProtocolUtil::IntToString(code);
            rsp_line += "";
            rsp_line += ProtocolUtil::CodetoDesc(code);
            rsp_line +="\n";
        }
        void MakeResponseHead(Request*&rq_)
        {
            rsp_head = "Content-Length: ";
            rsp_head += ProtocolUtil::IntToString(rq_->GetResourceSize());
            rsp_head += "\n";
            rsp_head += "Content-Type: ";
            std::string suffix_ = rq_->GetSuffix();
            rsp_head += ProtocolUtil::SuffixToType(suffix_);
            rsp_head += "\n";
        }
        void OpenResource(Request *&rq_)
        {
            std::string pathfd = rq_->GetPath();
            fd = open(rq_->GetPath().c_str(),O_RDONLY);
        }
        ~Response()
        {
            if(fd >= 0){
                close(fd);
            }
        }
};

class Connect{
    private:
        int sock;
    public:
        Connect(int sock_)
            :sock(sock_)
    {}
        int RecvOneLine(std::string &line_)
        {
            char c = 'X';
            while(c !='\n')
            {
                ssize_t s = recv(sock,&c,1,0);
                if(s > 0)
                {
                    if(c == '\r')
                    {//换行符有\n、\r\n,\r三种
                        recv(sock,&c,1,MSG_PEEK);//MSG_PEEK窥探功能，看看结果，不取走
                        if(c == '\n')
                        {
                            recv(sock,&c,1,0);
                        }
                        else
                        {
                            c = '\n';
                        }
                    }
                    line_.push_back(c);
                }
                else
                {
                    break;
                }
            }
            return line_.size();
        }

        void RecvRequestHead(std::string& head_)
        {
            head_ = "";
            std::string line_;
            while(line_ != "\n")
            {
                line_ = "";
                RecvOneLine(line_);
                head_ += line_;
            }
        }

        void RecvRequestText(std::string text_,int len_,std::string& param_)
        {
            char c_;
            int i = 0;
            while(i < len_)
            {
                recv(sock,&c_,1,0);
                text_.push_back(c_);
            }

            param_ = text_;
        }
        void SendResponse(Response *&rsp_,Request *&rq_)
        {
            if(rq_->IsCgi())
            {

            }else
            {
                send(sock,rsp_->rsp_line.c_str(),rsp_->rsp_line.size(),0);
                send(sock,rsp_->rsp_head.c_str(),rsp_->rsp_head.size(),0);
                send(sock,rsp_->blank.c_str(),rsp_->blank.size(),0);
                sendfile(sock,rsp_->fd,NULL,rq_->GetResourceSize());
            }
        }
        ~Connect()
        {
            if(sock>=0){
                close(sock);
            }
        }
};
class Entry{
    public:
        static int ProcessNonCgi(Connect *&conn_,Request *&rq_,Response *&rsp_)
        {
            int &code_ = rsp_->code;
            rsp_->MakeStatusLine();
            rsp_->MakeResponseHead(rq_);
            rsp_->OpenResource(rq_);
            conn_->SendResponse(rsp_,rq_);
        }
        static int ProcessResponse(Connect *&conn_,Request *&rq_,Response *&rsp_)
        {
            if(rq_->IsCgi())
            {
                //ProcessCgi();
            }else
            {
                ProcessNonCgi(conn_,rq_,rsp_);
            }
        }
        static void* HandlerRequest(void*arg_)
        {
            int sock_ = *(int*)arg_;
            delete (int*)arg_;
            Connect *conn_ =new Connect(sock_);
            Request *rq_ = new Request();
            Response *rsp_ = new Response();

            int &code_ = rsp_->code;
            conn_->RecvOneLine(rq_->rq_line);
            rq_->RequestLineParse();
            if( !rq_->IsMethodLegal() )
            {
                code_ = NOT_FOUND;
                goto end;
            }

            rq_->UriParse();
            if( !rq_->IsPathLegal())
            {
                code_ = NOT_FOUND;
                goto end;
            }

            LOG(INFO,"Request Path is OK!");

            conn_->RecvRequestHead(rq_->rq_head);
            if( rq_->RequestHeadParse())
            {
                LOG(INFO,"parse head done");
            }else
            {
                code_ = NOT_FOUND;
                goto end;
            }

            if(rq_->IsNeedRecvText())
            {
                conn_->RecvRequestText(rq_->rq_text,rq_->GetContentLength(),rq_->GetParam());
            }

            //request param done
            ProcessResponse(conn_,rq_,rsp_);

end:
            if(code_ != OK)
            {
                //HandlerError(sock_);
            }
            delete conn_;
            delete rq_;
            delete rsp_;
        }
};
#endif 
