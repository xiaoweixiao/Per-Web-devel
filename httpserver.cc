#include"httpserver.hpp"

static void Usage(std::string pro_c)
{
    std::cout<<"Usage "<<pro_c<<" port "<<std::endl;
}
int main(int argc,char* argv[])
{
    if(argc != 2){
        Usage(argv[0]);
        exit(1);
    }
    HttpdServer *serp = new HttpdServer(atoi(argv[1]));
    serp->InitServer();
    serp->Start();

    delete serp;
    return 0;
}
