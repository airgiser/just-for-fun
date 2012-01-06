#include <stdio.h>
#include <assert.h>
#include "event.h"
#include "thread.h"

#define MAX 19

typedef struct _SharedData
{
    int valarray[MAX];

    Event *event;
}SharedData;

#if defined(WIN32) || defined(WINCE)
unsigned long WINAPI thread_func(void *param)
#elif defined(LINUX) || defined(UNIX)
void *thread_func(void *param)
#endif
{
    int i = 0;
    SharedData *pData = (SharedData *)param;
    assert(pData);

    event_wait(pData->event);
    printf("This the sub thread!\n");
    for(i = 0; i < MAX; i++)
    {
        printf("S%d ", pData->valarray[i]);
    }
    printf("\n");

    return;
}

int main(int argc, char *argv[])
{
    int i = 0;
    SharedData data;
    data.event = event_create();

    HandleType ht = thread_start(&thread_func, &data);

    for(i = 0; i < MAX; i++)
    {
        data.valarray[i] = i;
        printf("M%d ", data.valarray[i]);

#if defined(WIN32) || defined(WINCE)
        Sleep(1);
#elif defined(LINUX) || defined(UNIX)
        usleep(1000);
#endif
    }
    printf("\n");
    event_signal(data.event);

    thread_wait(ht);

    event_destroy(data.event);
    printf("Complete.\n");

    return 0;
}
