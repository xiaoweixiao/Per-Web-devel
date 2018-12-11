#ifndef __HTTPDSERVER_HPP__
#define __HTTPDSERVER_HPP__

#include"protocolutil.hpp"
#include "Threadpool.hpp"
#include<pthread.h>

class HttpdServer{
private:
    int listen_sock;
    int port;
    ThreadPool *tp;
public:
    HttpdServer(int port_):port(port_),listen_sock(-1),tp(NULL)
    {}

    void InitServer()
    {
        listen_sock = socket(AF_INET,SOCK_STREAM,0);
        if(listen_sock < 0){
            LOG(ERROR,"socket error");
            exit(2);
        }
        int opt = 1;
        setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

        struct sockaddr_in local;
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = INADDR_ANY;

        if(bind(listen_sock,(struct sockaddr*)&local,sizeof(local))<0)
        {
            LOG(ERROR,"bind error");
            exit(3);
        }
        if(listen(listen_sock,5)<0){
            LOG(ERROR,"listen error");
            exit(4);
        }
        LOG(INFO,"InitServer Success!");

        tp = new ThreadPool();
        tp->InitThreadPool();
    }
    void Start()
    {
        LOG(INFO,"Server Start");
        for(;;){
            int sock_;
            struct sockaddr_in peer_;
            socklen_t len_=sizeof(peer_);
            sock_ = accept(listen_sock,(struct sockaddr*)&peer_,&len_);
            if(sock_ < 0){
                LOG(WARNING,"accept error");
                continue;
            }

            Task t(sock_,Entry::HandlerRequest);
            tp->PushTask(t);
        }
    }
    ~HttpdServer()
    {
        if(listen_sock != -1)
        {
            close(listen_sock);
        }
        port = -1;
    }
};
#endif


