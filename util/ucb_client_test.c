#include <stdio.h>
#include "ucb_socket.h"

#define SRVPORT 3688
#define MAX 256
int main(int argc, char *argv[])
{
    int socket_fd = 0;
    int recv_bytes = 0;
    char buf[MAX];
    int errno = 0;

    // Get server address.
    struct sockaddr_in serv_addr;
    if(argc < 2)
    {
        printf("Please enter the server address!");
        return 1;
    }
    errno = socket_get_addr(&serv_addr, argv[1], SRVPORT);
    if(errno == -1)
    {
        printf("Invalid server address!");
        return 1;
    }

    // Create socket.
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1)
    {
        printf("Failed to create socket!");
        return 1;
    } 

    // Connect to server.
    errno = connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
    if(errno == -1)
    {
        printf("Connect Failed!");
        return 1;
    }

    // Receive data from server.
    recv_bytes = recv(socket_fd, buf, MAX, 0);
    if(recv_bytes == -1)
    {
        printf("Recive Failed!");
        return 1;
    }
    buf[recv_bytes] = '\0';
    printf("Server: [%s]\n", buf);
    
    // Close socket
    close(socket_fd);

    return 0;
}
