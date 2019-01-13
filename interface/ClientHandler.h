
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

#include "../searchAlg/Bestfs.h"
#include "../Point.h"

template<class P, class S>//problem= matix<state<point>>, s= list<state<point>>
class ClientHandler {
protected:
    Solver<P, S> *solver;
    CacheManager *cacheManager;

public:
    ClientHandler(Solver<P, S> *solver, CacheManager *cacheManager) : solver(solver),
                                                                      cacheManager(
                                                                              cacheManager) {}

    virtual void handleClient(string inputFile, string outputFile) = 0;

};

#endif //PROJB_CLIENTHANDLER_H
