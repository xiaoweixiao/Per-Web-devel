g++ -o httpserver httpserver.cc -lpthread
In file included from /usr/include/c++/4.8.2/unordered_map:35:0,
                 from protocolutil.hpp:9,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/c++0x_warning.h:32:2: error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support is currently experimental, and must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
 #error This file requires compiler and library support for the \
  ^
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:31:29: error: ‘std::unordered_map’ has not been declared
     static void MakeKV(std::unordered_map<std::string,std::string> &kv_,std::string &str_)
                             ^
protocolutil.hpp:31:42: error: expected ‘,’ or ‘...’ before ‘<’ token
     static void MakeKV(std::unordered_map<std::string,std::string> &kv_,std::string &str_)
                                          ^
protocolutil.hpp: In static member function ‘static void ProtocolUtil::MakeKV(int)’:
protocolutil.hpp:33:28: error: ‘str_’ was not declared in this scope
         std::size_t pos_ = str_.find(": ");
                            ^
protocolutil.hpp:41:9: error: ‘kv_’ was not declared in this scope
         kv_.insert(make_pair(k_,v_));
         ^
protocolutil.hpp: At global scope:
protocolutil.hpp:78:5: error: ‘unordered_map’ in namespace ‘std’ does not name a type
     std::unordered_map<std::string,std::string> head_kv;
     ^
protocolutil.hpp: In member function ‘bool Request::RequestHeadParse()’:
protocolutil.hpp:140:38: error: ‘head_kv’ was not declared in this scope
                 ProtocolUtil::MakeKV(head_kv,sub_string_);
                                      ^
protocolutil.hpp: In member function ‘int Request::GetContentLength()’:
protocolutil.hpp:150:27: error: ‘head_kv’ was not declared in this scope
         std::string cl_ = head_kv["Content-Length"];
                           ^
make: *** [httpserver] Error 1
