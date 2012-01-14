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

double time_get_now(TimeInfo *cur_time);

/*
 * Return the number of seconds elapsed since
 * the Epoch, 1970-01-01 00:00:00 +000 (UTC).
 */
double time_get_timestamp();

void time_get_microsecond(TimeMicro *micro_time);
int time_get_delay(TimeMicro *start_time, TimeMicro *end_time, 
        TimeMicro *sub_time);

UCB_END

#endif/*UCB_TIME_H*/
