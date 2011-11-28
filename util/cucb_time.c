/*
 * File: cucb_time.c
 * Author: airfox <airgis@163.com>
 *
 * Brief: time utility
 */

#include "cucb_time.h"
#include <time.h>

#if defined(WIN32)
#include <windows.h>
#elif defined(UNIX) || defined(LINUX)
#include <sys/time.h>
#endif

void time_get_now(TimeInfo *cur_time)
{
	time_t t = time(NULL);
	struct tm *loc_time = localtime(&t);

	cur_time->year = loc_time->tm_year + 1900;
	cur_time->month = loc_time->tm_mon + 1;
	cur_time->day = loc_time->tm_mday;
	cur_time->hour = loc_time->tm_hour;
	cur_time->minute = loc_time->tm_min;
	cur_time->second = loc_time->tm_sec;
	cur_time->weekday = loc_time->tm_wday;

	return;
}

void time_get_microsecond(TimeMicro *micro_time)
{
#if defined(UNIX) || defined(LINUX)
	struct timeval time;
	gettimeofday(&time, NULL);

	micro_time->second = time->tv_sec;
	micro_time->microsecond = time->tv_usec;
#elif defined(WIN32)
#endif
	return;
}

void time_delay(TimeMicro *end_time, TimeMicro *start_time, TimeMicro *sub_time)
{
	if(start_time->second > end_time->second)
	{
		return;
	}
	if(start_time->second == end_time->second && 
			start_time->microsecond > end_time->microsecond)
	{
		return;
	}
	sub_time->second = end_time->second - start_time->second;
	sub_time->microsecond = end_time->microsecond - start_time->microsecond;
	if(sub_time->microsecond < 0)
	{
		sub_time->second--;
		sub_time->microsecond += 1000000;
	}
	return;
}
