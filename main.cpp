#include <stdio.h>
#include <stdlib.h>
#include "interface/Solver.h"
#include "solvers/StringReverser.h"
#include <string>
#include <iostream>
#include "./interface/Searchable.h"
#include "./searchable/Matrix.h"

using std::string;
using std::cout;
using std::endl;
namespace boot {
    int main() {
        int x = 5;
        State<int> ***ma = new State<int> **[x];
        for (int i = 0; i < x; i++) {
            ma[i] = new State<int> *[5];
            for (int j = 0; j < x; j++) {
                ma[i][j] = new State<int>(i*8 * j*0.89 + 5 - i/2 * i);
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; ++j) {
                cout << *ma[i][j] << "\t";
            }
            cout << endl;
        }


        // Searchable<int> *searchable = new Matrix<int>(ma, 5, 5);

        /*  string mo = "moshe";
          Solver<string, string> *s = new StringReverser();
          cout << s->solve("12345") << endl;*/
        return 0;
    }

};

int main(int argc, char **argv) {
    boot::main();
    return 0;
};