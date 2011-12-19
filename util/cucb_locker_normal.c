/*!
 * Copyright (c) airfox 2011
 *
 * \file cucb_locker_normal.c
 * \brief a normal locker for win32 or linux platform
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#include <string.h>
#elif defined(LINUX) || defined(UNIX)
#include <pthread.h>
#endif

#include "cucb_locker_normal.h"

typedef struct _PrivInfo
{
#if defined(WIN32) || defined(WINCE)
    CRITICAL_SECTION cs;
#elif defined(LINUX) || defined(UNIX)
    pthread_mutex_t mutex;
#endif
}PrivInfo;

static int locker_normal_lock(Locker *thiz)
{
    PrivInfo *priv = (PrivInfo *)thiz->priv;
#if defined(WIN32) || defined(WINCE)
    EnterCriticalSection(&(priv->cs));
    return 0;
#elif defined(LINUX) || defined(UNIX)
    return pthread_mutex_lock(&priv->mutex);
#endif
}

static int locker_normal_unlock(Locker *thiz)
{
    PrivInfo *priv = (PrivInfo *)thiz->priv;
#if defined(WIN32) || defined(WINCE)
    LeaveCriticalSection(&(priv->cs));
    return 0;
#elif defined(LINUX) || defined(UNIX)
    return pthread_mutex_unlock(&priv->mutex);
#endif
}

static void locker_normal_destroy(Locker *thiz)
{
    PrivInfo *priv = (PrivInfo *)thiz->priv;
#if defined(WIN32) || defined(WINCE)
    DeleteCriticalSection(&(priv->cs));
#elif defined(LINUX) || defined(UNIX)
    pthread_mutex_destroy(&priv->mutex);
#endif

    free(thiz);

    return;
}

Locker *locker_normal_create(void)
{
    Locker *thiz = (Locker *)malloc(sizeof(Locker) + sizeof(PrivInfo));
    PrivInfo *priv = 0;

    if(thiz != NULL)
    {
        thiz->lock = locker_normal_lock;
        thiz->unlock = locker_normal_unlock;
        thiz->destroy = locker_normal_destroy;

        priv = (PrivInfo *)thiz->priv;
#if defined(WIN32) || defined(WINCE)
        memset(&(priv->cs), 0, sizeof(CRITICAL_SECTION));
        InitializeCriticalSection(&(priv->cs));
#elif defined(LINUX) || defined(UNIX)
        pthread_mutex_init(&(priv->mutex), NULL);
#endif
    }
    
    return thiz;
}
