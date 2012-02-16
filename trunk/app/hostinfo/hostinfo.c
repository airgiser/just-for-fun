/*!
 * Copyright (c) airfox 2012.
 */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    char **pptr = NULL;
    struct in_addr addr;
    struct hostent *hostptr;

    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", argv[0]);
        exit(0);
    }

    if(inet_aton(argv[1], &addr) != 0)
    {
        hostptr = gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET);
    }
    else
    {
        hostptr = gethostbyname(argv[1]);
    }

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

    exit(0);
}
