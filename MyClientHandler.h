

#ifndef PROJB_MYCLIENTHANDLER_H
#define PROJB_MYCLIENTHANDLER_H

#include "./interface/ClientHandler.h"

class MyClientHandler : public ClientHandler {

public:
    ostream handleClient(istream istream) override;

};


#endif //PROJB_MYCLIENTHANDLER_H
