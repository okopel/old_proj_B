
#include "State.h"

template<class T>
bool State<T>::equal(State<T> *other) {
    return this->state == other->state;
}

template<class T>
State<T> *State<T>::getCameFrom() {
    return this->cameFrom;
}

template<class T>
double State<T>::getCost() {
    return this->cost;
}

template<class T>
void State<T>::setCost(double cost) {
    State::cost = cost;
}

template<class T>
void State<T>::setCameFrom(State<T> *cameFrom) {
    this->cameFrom = cameFrom;
}

