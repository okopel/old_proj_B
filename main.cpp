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
        State<int> **ma = new State<int> *;
        for (int i = 0; i < 5; i++) {
            ma[i] = new State<int>(2);
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; ++j) {
                cout << ma[i][j] << " ";
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