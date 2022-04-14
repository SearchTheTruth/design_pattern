#include "Singleton.h"

int main()
{
    ThreadPool *threadpool_1 = ThreadPool::getInstance();
    ThreadPool *threadpool_2 = ThreadPool::getInstance();

    threadpool_1->getThread();
    threadpool_2->getThread();
    threadpool_2->getThread();
    threadpool_2->getThread();
    return 0;
}