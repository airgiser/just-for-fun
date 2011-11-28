/*
 * File: cucb_time.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: time utility
 */

#ifndef CUCB_TIME_H_
#define CUCB_TIME_H_

#include "cucb_typedef.h"

CUCB_BEGIN

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

CUCB_END

#endif/*CUCB_TIME_H_*/
