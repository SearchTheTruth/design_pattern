#ifndef _SINGLETON_H
#define _SINGLETON_H
#include <mutex>
#include <iostream>

using namespace std;

class ThreadPool
{
public:
    static ThreadPool *getInstance();
    bool getThread();
private:
    ThreadPool() = default;
    static ThreadPool *uniqueInstance;
    static mutex mtx;
    int threadCnt = 3;
};

ThreadPool* ThreadPool::uniqueInstance = nullptr;
mutex ThreadPool::mtx;

ThreadPool* ThreadPool::getInstance()
{
    mtx.lock();
    if (uniqueInstance == nullptr)
        uniqueInstance = new ThreadPool();
    mtx.unlock();

    return uniqueInstance;
}

bool ThreadPool::getThread()
{
    cout << threadCnt << " thread can be used" << endl;
    if (threadCnt) {
        --threadCnt;
        cout << "Get thread from thread pool success!" << endl;
    }
}

#endif