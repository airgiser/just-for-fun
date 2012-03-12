/*!
 * Copyright (c) airfox 2011
 *
 * \file thread.h
 * \brief simple thread interface
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_THREAD_H
#define UCB_THREAD_H

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#include <process.h>
#elif defined(LINUX) || defined(UNIX)
#include <pthread.h>
#endif

#include "typedef.h"

UCB_BEGIN

/* typedef HandleType and ThreadFunc */
#if defined(WIN32) || defined(WINCE)
typedef HANDLE HandleType;
typedef unsigned int (__stdcall *ThreadFunc)(void *param);
#elif defined(LINUX) || defined(UNIX)
typedef pthread_t HandleType;
typedef void *(*ThreadFunc)(void *param);
#endif

/* Thread interface */
HandleType thread_start(ThreadFunc proc, void *param);
void thread_wait(HandleType handle);

#if defined(WIN32) || defined(WINCE)
void thread_release(HandleType handle);
#endif

UCB_END

#endif/*UCB_THREAD_H*/
