#ifndef PROJB_STATE_H
#define PROJB_STATE_H

using namespace std;

#include <stdio.h>
#include "State.h"

template<class T>
class State {
private:
    T state;
    double cost;
    State *cameFrom;
public:
    State(T mystate) : state(mystate) {}

    virtual bool equal(State<T> *other);

    State *getCameFrom();

    double getCost();

    void setCost(double cost);

    void setCameFrom(State<T> *cameFrom);
};


#endif //PROJB_STATE_H
