
#include "StringReverser.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

string StringReverser::solve(string p) {
    string s = p;
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

