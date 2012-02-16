#include <stdio.h>
#include "socket.h"

#define SRVPORT 3688
#define MAXLEN 256
int main(int argc, char *argv[])
{
    /* file descriptor referring to the socket.*/
    int socket_fd = 0;

    int recv_bytes = 0;
    char buf[MAXLEN];
    int errno = 0;

    /* Get server address. */
    if(argc < 2)
    {
        printf("Please enter the server address!");
        return -1;
    }

    /* Create socket. */
    /* Connect to server. */
    socket_fd = socket_open_clientfd(argv[1], SRVPORT);
    if(socket_fd == -1)
    {
        printf("Failed to open socket!");
        return -1;
    } 
    else if(socket_fd == -2)
    {
        printf("Invalid server address!");
        return -1;
    }

    /* Send a message to server. */
    errno = send(socket_fd, "Hello!", 7, 0);

    /* Receive data from server. */
    recv_bytes = recv(socket_fd, buf, MAXLEN, 0);
    if(recv_bytes == -1)
    {
        printf("Recive Failed!");
        return 1;
    }
    buf[recv_bytes] = '\0';
    printf("Server: [%s]\n", buf);
    
    /* Close socket. */
    close(socket_fd);

    return 0;
}
