/*
 * File: cucb_time.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: time utility
 */

typedef struct _TimeInfo
{
	int year;
	int month;
	int day;

	int hour;
	int minute;
	int second;

	int weekday;
}TimeInfo;

void time_get_now(TimeInfo *cur_time);
