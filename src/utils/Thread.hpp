#ifndef THREAD_HPP
#define THREAD_HPP

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "ErrorCode.hpp"

class Thread
{
    pthread_t thread_id;
    bool isCreated, isRunning;

    protected:
    static void *threadRoutine(void *arg);
    ErrorCode startThread();
    ErrorCode stopThread();

    public:
    virtual void run() = 0;
    Thread();
    ~Thread();
};


#endif //THREAD_HPP