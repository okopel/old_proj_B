#ifndef PROJB_SOLVER_H
#define PROJB_SOLVER_H

#include <stdio.h>
#include <string>

using std::string;

template<class P, class S>
class Solver {
public:
    Solver() {}

    virtual S *solve(P *p) = 0;
};


#endif //PROJB_SOLVER_H
