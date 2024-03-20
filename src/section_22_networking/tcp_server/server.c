#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to read the content of a file into a dynamically allocated buffer
char *read_file(const char *filename, long *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    char *content = (char *)malloc((*size + 1) * sizeof(char));
    if (!content) {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }

    fread(content, sizeof(char), *size, file);
    content[*size] = '\0'; // Null-terminate the content
    fclose(file);
    return content;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *html_content;
    long html_size;

    // Read the content of index.html
    html_content = read_file("./index.html", &html_size);
    if (!html_content) {
        exit(EXIT_FAILURE);
    }

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
        // create new socket from connections accepted, accepts waits for connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // echo request details
        recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Request: %s\n", buffer);

        // add basic headers with dprintf
        dprintf(new_socket, "HTTP/1.1 200 OK\r\n");
        dprintf(new_socket, "Content-Type: text/html\r\n");
        dprintf(new_socket, "Content-Length: %ld\r\n\r\n", html_size);
        
        // send te file contents
        send(new_socket, html_content, html_size, 0);
        printf("Response sent\n");

        close(new_socket);
    }

    // Free allocated memory
    free(html_content);

    return 0;
}
