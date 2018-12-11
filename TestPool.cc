#include "Threadpool.hpp"
#include <unistd.h>

int print(int number)
{
    std::cout << number << std::endl;
    return 0;
}

int main()
{
    ThreadPool *tp = new ThreadPool();
    tp->InitThreadPool();

    for(int i = 0;i < 1000;i++)
    {
        Task t(i,print);
        tp->PushTask(t);
        sleep(1);
    }
}
