//
// Created by okoprl on 1/4/19.
//

#ifndef PROJB_EQUAL_H
#define PROJB_EQUAL_H

#include "State.h"

template<class T>
class Equal {
private:
    State<T> *first;
    State<T> *secend;

    Equal(State<T> other);

};


#endif //PROJB_EQUAL_H
