/*!
 * Copyright (c) airfox 2011
 *
 * \file time.h
 * \brief time utility
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_TIME_H
#define UCB_TIME_H

#include "typedef.h"

UCB_BEGIN

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

UCB_END

#endif/*UCB_TIME_H*/
