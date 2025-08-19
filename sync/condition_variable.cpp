#include "condition_variable.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
using namespace coid;

condition_variable::condition_variable()
{
    #ifdef SYSTYPE_WIN
    InitializeConditionVariable(reinterpret_cast<CONDITION_VARIABLE*>(&_cv));
    #else
    pthread_cond_init(&_cv, nullptr);
    #endif
}

condition_variable::~condition_variable()
{
}


void condition_variable::notify_one()
{
    #ifdef SYSTYPE_WIN
    WakeConditionVariable(reinterpret_cast<CONDITION_VARIABLE*>(&_cv));
    #else
    pthread_cond_signal(&_cv);
    #endif
}

void condition_variable::notify_all()
{
    #ifdef SYSTYPE_WIN
    WakeAllConditionVariable(reinterpret_cast<CONDITION_VARIABLE*>(&_cv));
    #else
    pthread_cond_broadcast(&_cv);
    #endif
}

void condition_variable::wait(_comm_mutex& mx)
{
    #ifdef SYSTYPE_WIN
    SleepConditionVariableCS(reinterpret_cast<CONDITION_VARIABLE*>(&_cv), reinterpret_cast<CRITICAL_SECTION*>(&mx), 0);
    #else
    pthread_cond_wait(&_cv, &mx._mutex);
    #endif
}

bool condition_variable::wait_for(_comm_mutex& mx, uint ms)
{
    #ifdef SYSTYPE_WIN
    return SleepConditionVariableCS(reinterpret_cast<CONDITION_VARIABLE*>(&_cv), reinterpret_cast<CRITICAL_SECTION*>(&mx), ms);
    #else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += ms / 1000;
    ts.tv_nsec += (ms % 1000) * 1000000;
    return pthread_cond_timedwait(&_cv, &mx._mutex, &ts) == 0;
    #endif
}

