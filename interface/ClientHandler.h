
#ifndef PROJB_CLIENTHANDLER_H
#define PROJB_CLIENTHANDLER_H

#include <stdio.h>
#include <iostream>
#include <istream>
#include <ostream>
#include "Solver.h"
#include "CacheManager.h"

using namespace std;

template<class P, class S>
class ClientHandler {
protected:
    Solver<P *, S *> *solver;
    CacheManager<P *, S *> cacheManager;

public:
    virtual void handleClient(istream inputStream, ostream ostream);

//    ostream &operator<<(ostream &os) {
//        return os << this->toString();
//    }
};

#endif //PROJB_CLIENTHANDLER_H
