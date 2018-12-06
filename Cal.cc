#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
#include <string>

int main()
{
    if(getenv("Content-Length"))
    {
        int size_ = atoi(getenv("Content-Length"));
        std::string param_;
        char c_;
        while(size_)
        {
            read(0,&c_,1);
            param_.push_back(c_);
            size_--;
        }

        int a,b;
        sscanf(param_.c_str(),"a=%d&b=%d",&a,&b);//读取格式化的字符串中的数据
        std::cout << "<html" <<std::endl;
        std::cout << "<head>My Cal</head>" <<std::endl;
        std::cout << "<body>" <<std::endl;
        std::cout <<"<h3>" << a << "+" << b << "=" << a+b <<"</h3>" <<std::endl;
        std::cout <<"<h3>" << a << "-" << b << "=" << a-b <<"</h3>" <<std::endl;
        std::cout <<"<h3>" << a << "*" << b << "=" << a*b <<"</h3>" <<std::endl;
        if(b == 0)
        {
            std::cout << "div zero";
        }else
        {
            std::cout <<"<h3>" << a << "/" << b << "=" << a/b <<"</h3>" <<std::endl;
            std::cout <<"<h3>" << a << "%" << b << "=" << a%b <<"</h3>" <<std::endl;
        }
        std::cout <<"</body>" <<std::endl;
        std::cout <<"</html>" <<std::endl;
    }
    return 0;
}
