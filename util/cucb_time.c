/*
 * File: cucb_time.c
 * Author: airfox <airgis@163.com>
 *
 * Brief: time utility
 */

#include "cucb_time.h"
#include <time.h>

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
