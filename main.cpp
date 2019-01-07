#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"
#include "StringReverser.h"
#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::endl;
int main() {

    string mo = "moshe";
    Solver<string, string> *s = new StringReverser();
    cout << s->solve("12345") << endl;
    return 0;
}