
#include "MySerialServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <string>

using std::string;
using std::thread;
using std::ref;

template<class P, class S>
int MySerialServer<P, S>::open(int portno, ClientHandler<P, S> *clientHandler) {
    this->shouldStop = false;
    //todo thread
    thread *t = new thread(&MySerialServer::openServer, portno, ref(clientHandler), ref(shouldStop));
    return 8;
}

template<class P, class S>
void MySerialServer<P, S>::stop() {
    this->shouldStop = true;
}


