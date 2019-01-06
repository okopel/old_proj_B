#ifndef PROJB_MYTESTCLIENTHANDLER_H
#define PROJB_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver *solver;
    CacheManager *cacheManager;
public:
    void handleClient() override;
};


#endif //PROJB_MYTESTCLIENTHANDLER_H
