
#ifndef PROJB_STRINGREVERSER_H
#define PROJB_STRINGREVERSER_H

#include <string>
#include "Solver.h"

using namespace std;

template<class P, class S>

class StringReverser : public Solver<P, S> {
public:
    StringReverser(P *p);

    S *solve(P *p) override;
};


#endif //PROJB_STRINGREVERSER_H
