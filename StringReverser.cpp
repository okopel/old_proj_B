
#include "StringReverser.h"
#include <stdio.h>

using namespace std;

template<class P, class S>

S *StringReverser<P, S>::solve(P *p) {
    string s = p;
    s.reserve();
    return s;
}


template<class P, class S>
StringReverser<P, S>::StringReverser(P *p):Solver<P, S>(p) {
}
