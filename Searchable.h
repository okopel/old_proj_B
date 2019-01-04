
#ifndef PROJB_SEARCHABLE_H
#define PROJB_SEARCHABLE_H

#include "State.h"
#include <vector>

class Searchable {

    State *getInitialState();

    State *getIGoallState();

    vector<State *> *getAllPossibleStates(State *state);

};


#endif //PROJB_SEARCHABLE_H
