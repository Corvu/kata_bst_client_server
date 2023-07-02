#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

int main() {
    int error_code = 0;
    // socket, bind, connect, send, close

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Bind the socket to an address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // connect to localhost
    server_address.sin_port = htons(8080); // bind to port 8080
    error_code = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (error_code == -1) {
        std::cerr << "Failed to bind socket." << std::endl;
        close(client_socket);
        return 1;
    }

    // Send messages to server
    std::string message;
    while (true) {
        std::getline(std::cin, message);
        int send_len = send(client_socket, message.c_str(), message.length(), 0);
        if (send_len == -1) {
            std::cerr << "Failed to send message to server." << std::endl;
        }
    }

    // Close the socket
    close(client_socket);

    return 0;
}
