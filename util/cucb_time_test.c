#include "cucb_time.h"
#include <stdio.h>

#if defined(UNIX) || defined(LINUX)
#include <unistd.h>
#elif defined(WIN32)
#include <windows.h>
#endif

int main(int argc, char argv[])
{
	TimeInfo time;
	TimeMicro start;
	TimeMicro end;
	TimeMicro delay;

	/*get local time*/
	time_get_now(&time);
	printf("%d:%d:%d\n", time.year, time.month, time.day);
	printf("%d:%d:%d\n", time.hour, time.minute, time.second);
	printf("%d\n", time.weekday);

	/*get accurate time(microsecond)*/
	time_get_microsecond(&start);
#if defined(UNIX) || defined(LINUX)
	usleep(10000);
#elif defined(WIN32)
	Sleep(100);
#endif
	time_get_microsecond(&end);
	time_get_delay(&start, &end, &delay);

	printf("%d:%d\n", delay.second, delay.microsecond);
	return 0;
}
