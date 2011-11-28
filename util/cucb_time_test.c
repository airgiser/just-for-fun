#include "cucb_time.h"
#include <stdio.h>

int main(int argc, char argv[])
{
	TimeInfo time;
	time_get_now(&time);

	printf("%d:%d:%d\n", time.year, time.month, time.day);
	printf("%d:%d:%d\n", time.hour, time.minute, time.second);
	printf("%d\n", time.weekday);
	return 0;
}
