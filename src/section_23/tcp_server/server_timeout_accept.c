#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { // SOCK_STREAM === TCP
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET; // basic internet family
    address.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
    address.sin_port = htons(PORT); // @manpages: function converts the unsigned short integer hostshort from host byte order to network byte order.

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections, 3 is the maximun connection
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // don't accept connections
        sleep(1);
    }

    return 0;
}
