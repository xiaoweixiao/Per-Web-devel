#ifndef _THREAD_POOL_HPP
#define _THREAD_POOL_HPP

#include <iostream>
#include <queue>
#include "log.hpp"
#include <pthread.h>

typedef int (*handler_t)(int);
class Task{
    private:
        int sock;
        handler_t handler;
    public:
        Task(int sock_,handler_t handler_)
            :sock(sock_)
             ,handler(handler_)
    {}
        ~Task()
        {}

        void Run()
        {
            handler(sock);
        }
};

#define NUM 5

class ThreadPool{
    private:
        int thread_total_num;
        int thread_idle_num;
        std::queue<Task> task_queue;
        pthread_mutex_t lock;
        pthread_cond_t cond;

        volatile bool is_quit;
    private:
        static void* thread_routine(void*arg)
        {
            ThreadPool *tp = (ThreadPool*)arg;
            pthread_detach(pthread_self());//线程分离

            for(; ;){
                pthread_mutex_lock(&tp->lock);
                while(tp->task_queue.empty()){
                    if(tp->is_quit)
                    {
                        pthread_mutex_unlock(&tp->lock);
                        tp->thread_total_num--;
                        pthread_exit((void*)0);
                        LOG(INFO,"thread quit......");
                    }

                    tp->thread_idle_num++;
                    pthread_cond_wait(&tp->cond,&tp->lock);//使线程idle
                    tp->thread_idle_num--;
                }
                //醒来自动获得锁,且肯定有任务
                Task t = tp->task_queue.front();
                tp->task_queue.pop();
                //任务已经取出到t，所以释放锁
                pthread_mutex_unlock(&tp->lock);
                t.Run();
                LOG(INFO,"task has been taken,handler...");
                std::cout << "ID of Thread is:" << pthread_self() << std::endl;
            }
        }
    public:
        ThreadPool(int num_ = NUM)
            :thread_total_num(num_)
             ,thread_idle_num(0)
             ,is_quit(false)
    {
        pthread_mutex_init(&lock,NULL);
        pthread_cond_init(&cond,NULL);
    }

        void InitThreadPool()
        {
            int i_ = 0;
            for(i_;i_< thread_total_num;i_++){
                pthread_t tid;
                pthread_create(&tid,NULL,thread_routine,this);
            }
        }

        void PushTask(Task &t_)
        {
            pthread_mutex_lock(&lock);

            if(is_quit){ 
                pthread_mutex_unlock(&lock);
                return;
            }
            task_queue.push(t_);
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&lock);
        }

        void Stop()
        {
            pthread_mutex_lock(&lock);
            is_quit = true;
            pthread_mutex_unlock(&lock);

            //如果is_quit = true,就应该把idle状态的线程唤醒，让线程去任务队列取任务，判断is_quit,线程退出
            while(thread_idle_num > 0){
                pthread_cond_broadcast(&cond);
            }
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }
};
#endif
