/*!
 * \file cucb_thread.h
 * \brief simple thread interface
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_THREAD_H_
#define CUCB_THREAD_H_

#include "cucb_typedef.h"

CUCB_BEGIN

#if defined(WIN32) || defined(WINCE)
typedef HANDLE HandleType;
typedef unsigned (__stdcall *ThreadFunc)(void *param);
#elif defined(LINUX) || defined(UNIX)
typedef pthread_t HandleType;
typedef void *(*ThreadFunc)(void *param);
#endif

HandleType thread_start(ThreadFunc proc, void *param);
void thread_wait(HandleType handle);

CUCB_END

#endif/*CUCB_THREAD_H_*/
