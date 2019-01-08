
#ifndef PROJB_CLIENTHANDLER_H
#define PROJB_CLIENTHANDLER_H

#include <stdio.h>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

class ClientHandler {

public:
    virtual ostream handleClient(istream inputStream);

//    ostream &operator<<(ostream &os) {
//        return os << this->toString();
//    }
};

#endif //PROJB_CLIENTHANDLER_H
