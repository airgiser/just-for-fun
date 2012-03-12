/*!
 * Copyright (c) airfox 2012
 *
 * \file event.h
 * \brief simple event(thread) interface 
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_EVENT_H
#define UCB_EVENT_H

#include "typedef.h"

UCB_BEGIN

/* typedef */
struct _Event;
typedef struct _Event Event;

/* 
 * Create event. 
 */
Event *event_create();

/*
 * Signal the event.
 */
void event_signal(Event *thiz);

/*
 * Reset the event.
 */
void event_clear(Event *thiz);

/*
 * Wait until the event become signalled.
 */
void event_wait(Event *thiz);

/*
 * Release the event.
 */
void event_destroy(Event *thiz);

UCB_END

#endif/*UCB_EVENT_H*/
