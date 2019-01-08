
#ifndef PROJB_EQUAL_H
#define PROJB_EQUAL_H

#include "interface/State.h"

template<class T>
class Equal {
private:
    State<T> *first;
    State<T> *secend;

    Equal(State<T> other);

};


#endif //PROJB_EQUAL_H
