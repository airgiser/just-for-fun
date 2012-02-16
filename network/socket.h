/*!
 * Copyright (c) airfox 2012
 *
 * \brief socket operations
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_SOCKET_H
#define UCB_SOCKET_H

#if defined(WIN32) || defined(WINCE)
#elif defined(LINUX) || defined(UNIX)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#endif

#include "typedef.h"

UCB_BEGIN

#if defined(WIN32) || defined(WINCE)
#elif defined(LINUX) || defined(UNIX)
int socket_open_clientfd(char *hostname, int port);
int socket_open_listenfd(int port);
#endif

UCB_END

#endif/*UCB_SOCKET_H*/
