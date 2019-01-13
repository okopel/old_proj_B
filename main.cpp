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
        //        list<State<Pointm> *> *solve(Searchable<Pointm> *p);
        //<Matrix<Pointm>, list<State<Pointm> *> >;

//  auto x = new Bestfs<Pointm *>();
        auto cash = new FileCacheManager();


        /*      Solver<Matrix<Pointm>, list<State<Pointm> *> *> *solver = new Bestfs<Pointm>();
                 auto *myClientHandler = new MyClientHandler(solver, cash);*/


        auto solver = new Bestfs<Pointm>();
        cout << typeid(solver).name() << endl;
        cout << typeid(*solver).name() << endl;
        cout << typeid(&solver).name() << endl;
        /// cout << typeid(solver)<<endl;

        cout << typeid(MyClientHandler).name();


        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main(argc, argv);
    return 0;
};