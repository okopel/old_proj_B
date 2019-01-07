#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"
#include "StringReverser.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    string mo = "moshe";
    Solver<string, string> *s = new StringReverser<string, string>(&mo);
    cout << s->solve(&mo) << endl;
    return 0;
}