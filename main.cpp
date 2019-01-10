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
    int main() {

        auto *stringReve = new StringReverser();
        auto *cash = new FileCacheManager();
        auto *myCli = new MyStringClient(stringReve, cash);
        myCli->x();
/*
        using std::string;
        auto *bestfs = new Bestfs<int>();
        auto *cacheManager = new FileCacheManager();
        auto *myClientHandler = new MyClientHandler<Matrix<int> *, vector<State<int> *> >(bestfs, cacheManager);

        MyClientHandler<Matrix<int>, vector<State<int> > > b(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, vector<State<int> > > b2(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, vector<State<int> *> > b3(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, vector<State<int> *> *> b4(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, vector<State<int> *> > b5(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, vector<State<int> *> *> b6(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, vector<State<int> > *> b7(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, vector<State<int> > *> b8(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, list<State<int> > > c(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, list<State<int> > > c2(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, list<State<int> *> > c3(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, list<State<int> *> *> c4(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, list<State<int> *> > c5(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, list<State<int> *> *> c6(bestfs, cacheManager);
        MyClientHandler<Matrix<int>, list<State<int> > *> c7(bestfs, cacheManager);
        MyClientHandler<Matrix<int> *, list<State<int> > *> c8(bestfs, cacheManager);
*/

        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main();
    return 0;
};