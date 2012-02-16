/*!
 * Copyright (c) airfox 2012.
 */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

struct hostent *gethost(char *hostname)
{
    struct in_addr addr;
    struct hostent *hostptr;

    if(inet_aton(hostname, &addr) != 0)
    {
        hostptr = gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET);
    }
    else
    {
        hostptr = gethostbyname(hostname);
    }
}

void printhostinfo(struct hostent *hostptr)
{
    char **pptr = NULL;
    struct in_addr addr;

    printf("official hostname: %s\n", hostptr->h_name);

    for(pptr = hostptr->h_aliases; *pptr != NULL; pptr++)
    {
        printf("alias: %s\n", *pptr);
    }
    
    for(pptr = hostptr->h_addr_list; *pptr != NULL; pptr++)
    {
        addr.s_addr = ((struct in_addr *)*pptr)->s_addr;
        printf("address: %s\n", inet_ntoa(addr));
    }
}

int main(int argc, char *argv[])
{
    struct hostent *hostptr;

    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", argv[0]);
        exit(0);
    }

    hostptr = gethost(argv[1]);
    printhostinfo(hostptr);

    exit(0);
}
