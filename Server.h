

#ifndef PROJB_SERVER_H
#define PROJB_SERVER_H

#include "ClientHandler.h"

#define TIME_OUT=2

class Server {
protected:
    int socketId;
    bool shouldStop;

public:
    virtual int open(int port, ClientHandler *clientHandler) = 0;

    virtual void stop() = 0;

    //todo func to get info
};

#endif //PROJB_SERVER_H
