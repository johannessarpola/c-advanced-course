#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 3333
#define BUFFER_SIZE 255

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *hostp;
    char *host_addrp;
    int serv_addrlen = sizeof(serv_addr);
    int cli_addrlen = sizeof(cli_addr);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    { // SOCK_STREAM === TCP
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr)); // init struct
    bzero((char *)&cli_addr, sizeof(cli_addr));   // init struct

    serv_addr.sin_family = AF_INET;         // basic internet family
    serv_addr.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
    serv_addr.sin_port = htons(PORT);       // @manpages: function converts the unsigned short integer hostshort from host byte order to network byte order.

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
               (const void *)&optval, sizeof(int));

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %s:%d with UDP\n", inet_ntoa(serv_addr.sin_addr), PORT);

    int n;
    while (1)
    {

        // echo request details
        n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&cli_addr, &cli_addrlen);
        buffer[n] = '\0'; // Null terminate the received data

        // who send ya message
        hostp = gethostbyaddr((const char *)&cli_addr.sin_addr.s_addr,
                              sizeof(cli_addr.sin_addr.s_addr), AF_INET);
        host_addrp = inet_ntoa(cli_addr.sin_addr);

        printf("Received %s from %s (%s)\n", buffer, hostp->h_name, host_addrp);

        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&cli_addr, cli_addrlen);
        printf("... and sent it back");

        sleep(1);
    }
    return 0;
}
