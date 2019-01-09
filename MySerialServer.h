

#ifndef PROJB_MYSERIALSERVER_H
#define PROJB_MYSERIALSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <string.h>
#include "interface/Server.h"

template<class P, class S>
class MySerialServer : public server_side::Server<P, S> {
private:
    bool shouldStop;
public:
    static void openServer(int portno, ClientHandler<P *, S *> *clientHandler, bool shouldStop) {

        int sockfd, newsockfd, clilen, n;
        int hz = 5;//todo hz
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */
        listen(sockfd, hz);//todo timeout
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        while (!shouldStop) {

            /* If connection is established then start communicating */
            bzero(buffer, 256);
            n = read(newsockfd, buffer, 255);

            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Here is the message: %s\n", buffer);

            /* Write a response to the client */
            n = write(newsockfd, "I got your message", 18);//todo send     n = send(sockfd, c, strlen(c), MSG_EOR);

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }

    int open(int port, ClientHandler<P *, S *> *clientHandler) override;

    void stop() override;
};


#endif //PROJB_MYSERIALSERVER_H
