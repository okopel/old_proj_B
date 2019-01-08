#ifndef PROJB_STATE_H
#define PROJB_STATE_H


#include <stdio.h>
#include "State.h"
#include <ostream>
#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::ostream;
using std::iostream;
using std::vector;
using std::list;
using std::endl;

template<class T>
class State {
private:
    T state;
    double cost;
    State *cameFrom;
public:
    State(T mystate) : state(mystate) {}

    virtual bool equal(State<T> *other) {
        return this->state == other->state;
    }

    T getState() const {
        return state;
    }

    State *getCameFrom() {
        return this->cameFrom;
    }

    double getCost() {
        return this->cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool operator<(const State *other) {
        return this->cost < other->getCost();
    }


    friend ostream &operator<<(ostream &out, State<T> t) {
        return print(out, t);
    }
};

template<class T>
ostream &print(ostream &out, const State<T> &t) {
    return out << t.getState();

}


#endif //PROJB_STATE_H
