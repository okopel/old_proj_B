
#ifndef PROJB_CLIENTHANDLER_H
#define PROJB_CLIENTHANDLER_H

#include <stdio.h>
#include <iostream>
#include <istream>
#include <ostream>
#include "Solver.h"
#include "CacheManager.h"
#include <string>

using std::string;
using std::istream;
using std::ostream;

template<class P, class S>
class ClientHandler {
protected:
    Solver<P, S> *solver;
    CacheManager *cacheManager;

public:
    ClientHandler(Solver<P, S> *solver, CacheManager *cacheManager) : solver(solver),
                                                                      cacheManager(cacheManager) {}

    virtual void handleClient(istream inputStream, ostream ostream);

};

#endif //PROJB_CLIENTHANDLER_H
