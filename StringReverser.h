
#ifndef PROJB_STRINGREVERSER_H
#define PROJB_STRINGREVERSER_H


#include "Solver.h"
#include <stdio.h>
#include <string>

using std::string;

class StringReverser : public Solver<string, string> {
public:
    string solve(string p);
};


#endif //PROJB_STRINGREVERSER_H
