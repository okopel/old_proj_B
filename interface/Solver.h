#ifndef PROJB_SOLVER_H
#define PROJB_SOLVER_H

#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::type_info;
using namespace std;

template<class P, class S>
class Solver {
public:
    Solver() {}

    virtual S *solve(P p) = 0;
};


#endif //PROJB_SOLVER_H
