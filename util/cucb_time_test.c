#include "cucb_time.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char argv[])
{
	TimeInfo time;
	time_get_now(&time);

	printf("%d:%d:%d\n", time.year, time.month, time.day);
	printf("%d:%d:%d\n", time.hour, time.minute, time.second);
	printf("%d\n", time.weekday);

	/*获得精确时间(微秒)*/
	struct timeval start;
	struct timeval end;
	struct timeval sub;
	
	gettimeofday(&start, NULL);
	usleep(10000);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &sub);

	printf("%d\n", (int)sub.tv_usec);
	return 0;
}
