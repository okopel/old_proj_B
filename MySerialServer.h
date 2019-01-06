

#ifndef PROJB_MYSERIALSERVER_H
#define PROJB_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public Server {
    void openServer(int port, ClientHandler *clientHandler);
public:
    int open(int port, ClientHandler *clientHandler) override;

    void stop() override;
};


#endif //PROJB_MYSERIALSERVER_H
