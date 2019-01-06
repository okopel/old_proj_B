

#ifndef PROJB_SOLVER_H
#define PROJB_SOLVER_H

#include "Solution.h"
#include "Problem.h"

class Solver {
public:
    virtual Solution *solve(Problem *p) = 0;
};


#endif //PROJB_SOLVER_H
