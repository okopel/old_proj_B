#include <stdio.h>
#include <stdlib.h>
#include "interface/Solver.h"
#include "interface/CacheManager.h"
#include "solvers/StringReverser.h"
#include <string>
#include <iostream>
#include <fstream>
#include "./interface/Searchable.h"
#include "./searchable/Matrix.h"
#include "./interface/ClientHandler.h"
#include "MyClientHandler.h"
#include "searchAlg/Bestfs.h"
#include <vector>
#include "./cashManagers/FileCacheManager.h"
#include "MyStringReverseClient.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::ofstream;
using std::ostream;

namespace boot {
    int main(int argc, char **argv) {
        string input = argv[1];
        string output = argv[2];


        auto cashMa = new FileCacheManager();
        auto solver = new Bestfs<Pointm>();
        auto mch = new MyClientHandler(solver, cashMa);

        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main(argc, argv);
    return 0;
};