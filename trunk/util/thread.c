/*!
 * Copyright (c) airfox 2011
 *
 * \file thread.c
 * \brief simple thread interface
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#include <process.h>
#elif defined(LINUX) || defined(UNIX)
#include <pthread.h>
#endif

#include <stdlib.h>
#include "thread.h"

HandleType thread_start(ThreadFunc proc, void *param)
{
    HandleType handle = 0;
#if defined(WIN32) || defined(WINCE)
    unsigned int id = 0;
    handle = (HANDLE)_beginthreadex(NULL, 0, 
                proc, param, 0, &id);
#elif defined(LINUX) || defined(UNIX)
    pthread_create(&handle, NULL, proc, param);
#endif

    return handle;
}

void thread_wait(HandleType handle)
{
#if defined(WIN32) || defined(WINCE)
    WaitForSingleObject(handle, INFINITE);
#elif defined(LINUX) || defined(UNIX)
    pthread_join(handle, NULL);
#endif

    return;
}

#if defined(WIN32) || defined(WINCE)
void thread_release(HandleType handle)
{
    CloseHandle(handle);

    return;
}
#endif
