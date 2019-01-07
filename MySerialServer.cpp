
#include "MySerialServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <string.h>

using std::thread;

int MySerialServer::open(int portno, ClientHandler *clientHandler) {
    this->shouldStop = false;
    //todo thread
    thread *t = new thread(&MySerialServer::openServer, portno, ref(clientHandler), ref(shouldStop));
    return 8;
}


void MySerialServer::stop() {
    this->shouldStop = true;
}


