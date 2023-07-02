#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

int main() {
    int error_code = 0;
    // socket, bind, listen, accept, recv, close

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Bind the socket to an address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // use any available interface
    server_address.sin_port = htons(8080); // bind to port 8080
    error_code = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (error_code == -1) {
        std::cerr << "Failed to bind socket." << std::endl;
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    error_code = listen(server_socket, 3);
    if (error_code == -1) {
        std::cerr << "Failed to listen for incoming connections." << std::endl;
        close(server_socket);
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_address;
    socklen_t addrlen = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &addrlen);
    if (client_socket == -1) {
        std::cerr << "Failed to accept incoming connection." << std::endl;
        close(server_socket);
        return 1;
    }

    // Send data to the client
    /*const char *message = "Hello, client!";
    int send_len = send(client_socket, message, strlen(message), 0);
    if (send_len == -1) {
        std::cerr << "Failed to send message to client." << std::endl;
        close(client_socket);
        close(server_socket);
        return 1;
    }*/

    // Recieve data from the client
    char buffer[1024] = {0};
    while (true) {
        int recv_len = recv(client_socket, buffer, 1024, 0);
        if (recv_len == -1) {
            std::cerr << "Failed to recieve message from the client." << std::endl;
            close(client_socket);
            close(server_socket);
            return 1;
        }
        std::cout << "Client message: " << buffer << std::endl;
    }

    
    // Close the sockets
    close(client_socket);
    close(server_socket);

    std::cout << "Success." << std::endl;

    return 0;
}
