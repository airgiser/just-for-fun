#include <stdio.h>
#include "ucb_socket.h"

#define SRVPORT 3688
#define MAX 10
int main(int argc, char *argv[])
{
    int listen_fd = 0;
    int client_fd = 0;
    int errno = 0;

    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;

    int s_size = sizeof(struct sockaddr);
    int sin_size = sizeof(struct sockaddr_in);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1)
    {
        printf("Failed to create socket!");
        return 1;
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SRVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);

    errno = bind(listen_fd, (struct sockaddr *)&my_addr, s_size); 
    if(errno == -1)
    {
        printf("Binding Failed!");
        return 1;
    }

    errno = listen(listen_fd, MAX);
    if(errno == -1)
    {
        printf("Listening Failed!");
        return 1;
    }
    printf("Listening...\n");

    while(1)
    {
        client_fd = accept(listen_fd, (struct sockaddr *)&remote_addr, &sin_size);
        if(client_fd == -1)
        {
            printf("Accept Failed!");
            continue;
        }

        printf("Recived a connection from %s ", inet_ntoa(remote_addr.sin_addr));
        if(!fork())
        {
            errno = send(client_fd, "Welcome!", 9, 0);
            if(errno == -1)
            {
                printf("Send Failed!");
                close(client_fd);
                return 1;
            }
            close(client_fd);
        }
    }

    return 0;
}
