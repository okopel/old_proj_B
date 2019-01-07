#ifndef PROJB_SOLVER_H
#define PROJB_SOLVER_H

template<class P, class S>
class Solver {
    P *p;
public:
    Solver(P *p) : p(p) {}

    virtual S *solve(P *p) = 0;
};


#endif //PROJB_SOLVER_H
