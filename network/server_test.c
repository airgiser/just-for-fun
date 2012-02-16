#include <stdio.h>
#include "socket.h"

#define SERVERPORT 3688
#define MAXLEN 100
int main(int argc, char *argv[])
{
    /* file descriptor referring to the socket.*/
    int clientfd = 0;
    struct sockaddr_in clientaddr;
    int sin_size = sizeof(struct sockaddr_in);

    char buf[MAXLEN];
    int recv_bytes = 0;

    int listenfd = socket_open_listenfd(SERVERPORT);
    if(listenfd < 0)
    {
        return -1;
    }
    printf("Listening...\n");

    while(1)
    {
        /* Accept a connection on the socket. */
        /* On success, return the accepted socket. */
        clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &sin_size);
        if(clientfd == -1)
        {
            printf("Accept Failed!");
            continue;
        }
        printf("Recived a connection from %s\n",inet_ntoa(clientaddr.sin_addr));

        if(!fork())
        {
            /* Receive data from server. */
            recv_bytes = recv(clientfd, buf, MAXLEN, 0);
            if(recv_bytes == -1)
            {
                printf("Recive Failed!");
                return 1;
            }
            buf[recv_bytes] = '\0';
            printf("Client: [%s]\n", buf);

            /* Send a message to client. */
            if(send(clientfd, "Welcome!", 9, 0) < 0)
            {
                printf("Send Failed!");
                close(clientfd);
                return 1;
            }
            close(clientfd);
        }
    }

    return 0;
}
