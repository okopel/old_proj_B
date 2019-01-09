#include <stdio.h>
#include <stdlib.h>
#include "interface/Solver.h"
#include "solvers/StringReverser.h"
#include <string>
#include <iostream>
#include <fstream>
#include "./interface/Searchable.h"
#include "./searchable/Matrix.h"
#include "./interface/ClientHandler.h"
#include "MyClientHandler.h"
#include "searchAlg/Bestfs.h"
#include "./cashManagers/FileCacheManager.h"

using std::string;
using std::cout;
using std::endl;

namespace boot {
    int main() {
        using std::string;
        Solver<Matrix<int> *, list<State<int> *> *> *solver = new Bestfs<int>();
        CacheManager<Matrix<int> *, string> *cacheManager = new FileCacheManager<Matrix<int> *, string>();
        //ClientHandler<Matrix<int> *, string> *clientHandler = new MyClientHandler<Matrix<int> *, string> (solver,
        //                                                                                                cacheManager);
        ClientHandler<Matrix<int> *, string> clientHandler(solver, cacheManager);

        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main();
    return 0;
};