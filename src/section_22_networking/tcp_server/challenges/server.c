#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void)
{
    short sock_fd;
    printf("Created the socket\n");
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    return sock_fd;
}

int bindCreatedSocket(int sock_fd)
{
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); /* Local port */

    iRetval = bind(sock_fd, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main(int argc, char *argv[])
{
    int sock_fd = 0, new_sock_fd = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};

    // Create socket
    sock_fd = socketCreate();

    if (sock_fd == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if (bindCreatedSocket(sock_fd) < 0)
    {
        // print the error message
        perror("bind failed.");
        return 1;
    }

    printf("bind done\n");

    // Listen
    listen(sock_fd, 3);

    printf("Waiting for incoming connections...\n");
    clientLen = sizeof(struct sockaddr_in);

    // accept connection from an incoming client
    new_sock_fd = accept(sock_fd, (struct sockaddr *)&client, (socklen_t *)&clientLen);

    if (new_sock_fd < 0)
    {
        perror("accept failed");
        return 1;
    }

    printf("Connection accepted\n");
    memset(client_message, '\0', sizeof client_message);
    memset(message, '\0', sizeof message);

    // Receive a reply from the client
    if (recv(new_sock_fd, client_message, 200, 0) < 0)
    {
        printf("recv failed");
    }

    printf("Received from Client: %s\n", client_message);

    int i = atoi(client_message);
    i--;
    sprintf(message, "%d", i);

    close(new_sock_fd);

    printf("Waiting for incoming connections...\n");

    // accept connection from an incoming client
    new_sock_fd = accept(sock_fd, (struct sockaddr *)&client, (socklen_t *)&clientLen);

    if (new_sock_fd < 0)
    {
        perror("accept failed");
        return 1;
    }

    printf("Connection accepted\n");

    // Send some data
    if (send(new_sock_fd, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }

    return 0;
}
