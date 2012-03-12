#include <stdio.h>
#include <string.h>
#include "locker_normal.h"
#include "thread.h"

#define MAX 500
typedef struct _SharedData
{
    int i;
    char str[MAX + 1];

    Locker *locker;
}SharedData;

#if defined(WIN32) || defined(WINCE)
unsigned long WINAPI thread_func(void *param)
#elif defined(LINUX) || defined(UNIX)
void *thread_func(void *param)
#endif
{
    SharedData *pdata = (SharedData *)param;
    while(1)
    {
        locker_lock(pdata->locker);

        if(pdata->i >= MAX)
        {
            locker_unlock(pdata->locker);
            break;
        }
#if defined(WIN32) || defined(WINCE)
        Sleep(1);
#elif defined(LINUX) || defined(UNIX)
        usleep(1000);
#endif
        (pdata->str)[pdata->i] = 'O';
        assert(strlen(pdata->str) == pdata->i + 1);
        (pdata->i)++;
        printf("%d\n%s\n", pdata->i, pdata->str);

        locker_unlock(pdata->locker);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    HandleType h_one;
    HandleType h_two;

    SharedData data;
    data.i = 0;
    memset(data.str, 0, MAX + 1);
    data.locker = locker_normal_create();

    h_one = thread_start(thread_func, &data);
    h_two = thread_start(thread_func, &data);
    thread_wait(h_one);
    thread_wait(h_two);

    locker_destroy(data.locker);
    printf("Complete.\n");

    return 0;
}
