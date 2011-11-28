#include "cucb_time.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char argv[])
{
	/*获得系统时间*/
	TimeInfo time;
	time_get_now(&time);

	printf("%d:%d:%d\n", time.year, time.month, time.day);
	printf("%d:%d:%d\n", time.hour, time.minute, time.second);
	printf("%d\n", time.weekday);

	/*获得精确时间(微秒)*/
	TimeMicro start;
	TimeMicro end;
	TimeMicro delay;
	
	time_get_microsecond(&start);
	usleep(10000);
	time_get_microsecond(&end);
	time_get_delay(&start, &end, &delay);

	printf("%d:%d\n", delay.second, delay.microsecond);
	return 0;
}
