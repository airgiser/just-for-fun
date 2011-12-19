/*!
 * Copyright (c) airfox 2011
 *
 * \file cucb_time.h
 * \brief time utility
 *
 * \author airfox <airgis@163.com>
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

typedef struct _TimeMicro
{
    int second;
    int microsecond;/*1/1000000 second*/
}TimeMicro;

void time_get_now(TimeInfo *cur_time);

void time_get_microsecond(TimeMicro *micro_time);
int time_get_delay(TimeMicro *start_time, TimeMicro *end_time, 
        TimeMicro *sub_time);

CUCB_END

#endif/*CUCB_TIME_H_*/
