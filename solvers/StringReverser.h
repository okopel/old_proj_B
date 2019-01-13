
#ifndef PROJB_STRINGREVERSER_H
#define PROJB_STRINGREVERSER_H


#include "../interface/Solver.h"
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <string.h>

using std::string;

class StringReverser : public Solver<string *, string> {
public:
    string solve(string p);

    string *solve(string *p) override;
};


#endif //PROJB_STRINGREVERSER_H
