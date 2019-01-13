#ifndef PROJB_STATE_H
#define PROJB_STATE_H

#include <stdio.h>
#include "State.h"
#include <ostream>
#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::string;
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
    int cost;
    State<T> *cameFrom;

public:
    State(T mystate) : state(mystate) {}

    virtual bool operator==(State<T> *other) {
        return this->state == other->state;
    }

    T getT() const {
        return state;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    int getCost() {
        return this->cost;
    }

    void setCost(int cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool operator<(const State<T> *other) {
        return this->cost < other->getCost();
    }


    friend ostream &operator<<(ostream &out, State<T> *t) {
        return print(out, t);
    }
};

template<class T>
ostream &print(ostream &out, const State<T> &t) {
    return out << t.getT();

}


#endif //PROJB_STATE_H
