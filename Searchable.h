
#ifndef PROJB_SEARCHABLE_H
#define PROJB_SEARCHABLE_H

#include "State.h"
#include <vector>
template<class T>
class Searchable {
private:

public:

    State<T> *getInitialState();

    State<T> *getIGoallState();

    vector<State<T> *> *getAllPossibleStates(State<T> *state);

};


#endif //PROJB_SEARCHABLE_H
