#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 3333
#define BUFFER_SIZE 255
#define SERVER_IP "127.0.0.1"

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char read_buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) // SOCK_STREAM === TCP
    {
        perror("socket creation failed");
        return -1;
    }
    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int data_size = 20;
    char *data = "Hello from client";


    int n = 0, len = 0;
    sendto(sock, (const char *)data, data_size, MSG_CONFIRM, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Message sent to server: %s\n", data);

    n = recvfrom(sock, (char *)read_buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&serv_addr, &len);
    read_buffer[n] = '\0'; // Null terminate the received data
    printf("Response from server: %s\n", read_buffer);

    close(sock);
    return 0;
}
