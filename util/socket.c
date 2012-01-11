/*
 * Copyright (c) airfox 2012
 *
 * \brief socket util
 * \author airfox<airgis@163.com>
 */

#include <assert.h>
#include "socket.h"


#if defined(WIN32) || defined(WINCE)
#elif defined(LINUX) || defined(UNIX)
int socket_get_addr(struct sockaddr_in *addr, char *address, unsigned int port)
{
    struct hostent *host = NULL;
    assert(addr != NULL && address != NULL);

    host = gethostbyname(address);
    if(host == NULL)
    {
        return -1;
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(addr->sin_zero), 8);

    return 0;
}
#endif
