#ifndef PROJB_MYTESTCLIENTHANDLER_H
#define PROJB_MYTESTCLIENTHANDLER_H

#include "interface/ClientHandler.h"
#include "interface/Solver.h"
#include "interface/CacheManager.h"
#include "parser/Parser.h"

template<class P, class S>
class MyTestClientHandler : public ClientHandler<P, S> {
public:
    void handleClient() override;
};


#endif //PROJB_MYTESTCLIENTHANDLER_H
