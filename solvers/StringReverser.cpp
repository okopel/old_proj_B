
#include "StringReverser.h"
#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::swap;

string StringReverser::solve(string p) {
    string s = p;
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

