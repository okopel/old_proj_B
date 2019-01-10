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
        auto *bestfs = new Bestfs<int>();
        auto *cacheManager = new FileCacheManager();
        auto *myClientHandler = new MyClientHandler<Matrix<int> *, list<State<int> *> *>(bestfs, cacheManager);
//        MyClientHandler(Solver<P, S> *solver, CacheManager *cacheManager);

        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main();
    return 0;
};