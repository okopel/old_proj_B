#ifndef PROJB_SOLVER_H
#define PROJB_SOLVER_H

#include <stdio.h>

template<class P, class S>
class Solver {
//    P *p;
public:
    Solver() {}

    virtual S solve(P p) = 0;
};


#endif //PROJB_SOLVER_H
