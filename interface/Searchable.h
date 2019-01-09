
#ifndef PROJB_SEARCHABLE_H
#define PROJB_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <string>
#include <stdio.h>

using std::string;

template<class T>
class Searchable {
protected:
    State<T> *initState;
    State<T> *goalState;
public:

    virtual State<T> *getInitialState() {
        return this->initState;
    }

    virtual State<T> *getIGoallState() {
        return this->goalState;
    }

    virtual vector<State<T> *> *getAllPossibleStates(State<T> *state) = 0;

};


#endif //PROJB_SEARCHABLE_H
