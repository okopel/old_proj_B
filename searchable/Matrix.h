#ifndef PROJB_MATRIX_H
#define PROJB_MATRIX_H

#include "../interface/Searchable.h"
#include "../interface/State.h"
#include <iostream>
#include <string>

using std::string;

template<class T>
class Matrix : public Searchable<T> {
    State<T> **matrix;
    int height;
    int width;

    vector<State<T> *> *getAllPossibleStates(int x, int y);

    State<T> *getStateByIndex(int x, int y);

public:
    Matrix(State<T> ***s, int height, int width, int initX, int initY, int goalX, int goalY);

    State<T> *getInitialState() override;

    State<T> *getIGoallState() override;

    vector<State<T> *> *getAllPossibleStates(State<T> *state) override;

};


#endif //PROJB_MATRIX_H
