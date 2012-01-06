/*
 * Copyrignt (c) airfox 2012
 *
 * \brief Implement of event for win32 & linux & unix platform 
 * \author airfox<airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <pthread.h>
#endif

#include <stdlib.h>
#include <assert.h>

typedef struct _Event
{
#if defined(WIN32) || defined(WINCE)
    HANDLE event;
#elif defined(LINUX) || defined(UNIX)
    pthread_cond_t condition;
    pthread_mutex_t mutex;
    int signalled;
#endif
}Event;

Event *event_create()
{
    Event *thiz = (Event *)malloc(sizeof(Event));
    assert(thiz != NULL);

    if(thiz != NULL)
    {
#if defined(WIN32) || defined(WINCE)
        thiz->event = CreateEvent(NULL, 1, 0, NULL);
#elif defined(LINUX) || defined(UNIX)
        pthread_mutex_init(&(thiz->mutex), NULL);
        pthread_cond_init(&(thiz->condition), NULL);
        thiz->signalled = 0;
#endif
    }

    return thiz;
}

void event_signal(Event *thiz)
{
    assert(thiz != NULL);
    
    if(thiz != NULL)
    {
#if defined(WIN32) || defined(WINCE)
        SetEvent(thiz->event);
#elif defined(LINUX) || defined(UNIX)
        pthread_mutex_lock(&(thiz->mutex));

        thiz->signalled = 1;
        pthread_cond_signal(&(thiz->condition));

        pthread_mutex_unlock(&(thiz->mutex));
#endif
    }
}

void event_clear(Event *thiz)
{
    assert(thiz != NULL);

    if(thiz != NULL)
    {
#if defined(WIN32) || defined(WINCE)
        ResetEvent(thiz->event);
#elif defined(LINUX) || defined(UNIX)
        pthread_mutex_lock(&(thiz->mutex));

        thiz->signalled = 0;

        pthread_mutex_unlock(&(thiz->mutex));
#endif
    }
}

void event_wait(Event *thiz)
{
    assert(thiz != NULL);

    if(thiz != NULL)
    {
#if defined(WIN32) || defined(WINCE)
        WaitForSingleObject(thiz->event, INFINITE);
#elif defined(LINUX) || defined(UNIX)
        pthread_mutex_lock(&(thiz->mutex));

        while(!(thiz->signalled))
        {
            pthread_cond_wait(&(thiz->condition), &(thiz->mutex));
        }

        pthread_mutex_unlock(&(thiz->mutex));
#endif
    }
}

void event_destroy(Event *thiz)
{
    if(thiz != NULL)
    {
#if defined(WIN32) || defined(WINCE)
        CloseHandle(thiz->event);
#elif defined(LINUX) || defined(UNIX)
        pthread_cond_destroy(&(thiz->condition));
        pthread_mutex_destroy(&(thiz->mutex));
#endif
    }
    free(thiz);

    return;
}
