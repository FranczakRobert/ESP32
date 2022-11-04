#include "Thread.hpp"

Thread::Thread(): isCreated(false), isRunning(false){}
Thread::~Thread(){}
 
void* Thread::threadRoutine(void *arg)
{  
    if(NULL != arg)
    {
        Thread* obj = static_cast<Thread*>(arg);

            while (obj->isRunning)
            {
                obj->run();
                usleep(10000);
            }
    }
    else
    {
        printf("[Thread] [threadRoutine] - object is NULL\n");
    }

    return NULL;
}

ErrorCode Thread::startThread()
{
    ErrorCode eResult = E_NOT_OK;
    if(!isCreated)
    {
        isRunning = true;
        if(0 == pthread_create(&thread_id,NULL,threadRoutine,this))
        {
            isCreated = true;
            printf("[Thread] [startThread] - start thread Successful\n");
            eResult = E_OK;
        }
        else
        {
            printf("[Thread] [startThread] - start thread Failed\n");
        }
    }
    else
    {
        printf("[Thread] [startThread] - Thread already running\n");
        eResult = E_OK;
    }

    return eResult;
}

ErrorCode Thread::stopThread()
{
    ErrorCode eResult = E_NOT_OK;

    if(isCreated && isRunning)
    {
        pthread_join(thread_id,NULL);
    }

    return E_OK;
}


