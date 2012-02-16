/**
 * Copyright (c) airfox 2012
 *
 * \brief socket util
 * \author airfox<airgis@163.com>
 */

#include <assert.h>
#include "socket.h"

#if defined(WIN32) || defined(WINCE)
#elif defined(LINUX) || defined(UNIX)
static int socket_get_addr(struct sockaddr_in *addr, char *address, int port)
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

int socket_open_clientfd(char *hostname, int port)
{
    int clientfd;
    struct sockaddr_in serveraddr;

    /* Create socket descriptor*/
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd < 0)
    {
        return -1;
    }

    /* Fill in the server's IP address and port*/
    if(socket_get_addr(&serveraddr, hostname, port) < 0)
    {
        return -2;
    }

    /* Establish a connection with the server */
    if(connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))<0)
    {
        return -1;
    }

    return clientfd;
}

int socket_open_listenfd(int port)
{
    int listenfd;
    int optval = 1;
    struct sockaddr_in serveraddr;

    /*Create socket descriptor*/
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        return -1;
    }

    /*Eliminates "Address already in use" error from bind*/
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, 
                (const void *)&optval, sizeof(int)) < 0)
    {
        return -1;
    }

    /* Bind a name to the socket*/
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons((unsigned short)port);
    serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
    bzero(&(serveraddr.sin_zero), 8);
    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        return -1;
    }

    /* Listen for connections on the socket. */
    if(listen(listenfd, 1024) < 0)
    {
        return -1;
    }

    return listenfd;
}
#endif
