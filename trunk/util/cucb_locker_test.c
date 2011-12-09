#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cucb_locker_normal.h"
#include "cucb_thread.h"

#define MAX 500
typedef struct _SimpleData
{
	int i;
	char str[MAX + 1];

	Locker *locker;
}SimpleData;

void *thread_func(void *param)
{
	SimpleData *pdata = (SimpleData *)param;
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

	return NULL;
}

int main(int argc, char *argv[])
{
	SimpleData data;
	data.i = 0;
	memset(data.str, 0, MAX + 1);
	data.locker = locker_normal_create();

	HandleType h_one = thread_start(thread_func, &data);
	HandleType h_two = thread_start(thread_func, &data);
	thread_wait(h_one);
	thread_wait(h_two);

	locker_destroy(data.locker);
	printf("Complete.\n");

	return 0;
}
