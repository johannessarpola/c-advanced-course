#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = 0, nread;
    struct sockaddr_in serv_addr;
    char read_buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) // SOCK_STREAM === TCP
    {
        perror("socket creation failed");
        return -1;
    }

    // timeout struct
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    // handle SND timeout
    if(setsockopt(sock,SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        perror("setting timeout failed");
        return -1;
    }

    // handle RCV timeout
    if(setsockopt(sock,SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        perror("setting timeout failed");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    // we dont need address.sin_addr.s_addr as s_addr reference to listen address
    serv_addr.sin_port = htons(PORT);

    // inet_pton - convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("invalid address");
        return -1;
    }

    // connect - initiate a connection on a socket
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connection Failed");
        return -1;
    }

    int data_size = 20;
    char *data = "Hello from client";

    send(sock, data, data_size, 0);
    printf("sent message to the server\n");

    nread = recv(sock, read_buffer, BUFFER_SIZE, 0);
    if (nread < 0) {
        perror("error reading from socket");
        return 1;
    } else {
        printf("response (%d length) from server:\n%s", nread, read_buffer);
    }
    fflush(stdout);
    close(sock);
    return 0;
}
