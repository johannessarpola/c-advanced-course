#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

// Create a Socket for server communication
short socketCreate(void)
{
    short sock_fd;
    printf("Create the socket\n");
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    return sock_fd;
}

// try to connect with server
int socketConnect(int sock_fd)
{
    int iRetval = -1;
    int ServerPort = 12345;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(sock_fd, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int sock_fd, char *request, short request_length)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if (setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(sock_fd, request, request_length, 0);
    return shortRetval;
}

// main driver program
int main(int argc, char *argv[])
{
    int sock_fd = 0;

    char sendToServer[100] = {0};

    // Create socket
    sock_fd = socketCreate();

    if (sock_fd == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    // Connect to remote server
    if (socketConnect(sock_fd) < 0)
    {
        perror("connect failed.\n");
        return 1;
    }

    printf("Sucessfully conected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    // Send data to the server
    socketSend(sock_fd, sendToServer, strlen(sendToServer));

    close(sock_fd);
    return 0;
}