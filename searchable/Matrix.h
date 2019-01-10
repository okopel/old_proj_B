#ifndef PROJB_MATRIX_H
#define PROJB_MATRIX_H

#include "../interface/Searchable.h"
#include "../interface/State.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <list>

using std::string;

template<class T>
class Matrix : public Searchable<T> {
    State<T> ***matrix;
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


template<class T>
State<T> *Matrix<T>::getIGoallState() {
    return Searchable<T>::getIGoallState();
}

template<class T>
vector<State<T> *> *Matrix<T>::getAllPossibleStates(State<T> *state) {
    int x = -1;
    int y = -1;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (matrix[i][j] == state) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }
    if (x == -1) {
        return nullptr;
    }
    return this->getAllPossibleStates(x, y);
}

template<class T>
vector<State<T> *> *Matrix<T>::getAllPossibleStates(int x, int y) {
    if (x < 0 || y < 0 || x > this->width || y > this->height) {
        return nullptr;
    }
    vector<State<T> *> *posStates = new vector<State<T> *>();
    if (x < this->width) {//rohav
        posStates->push_back(this->getStateByIndex(x + 1, y));
    }
    if (x > 0) {
        posStates->push_back(this->getStateByIndex(x - 1, y));
    }
    if (y < this->height) {
        posStates->push_back(this->getStateByIndex(x, y + 1));
    }
    if (y > 0) {
        posStates->push_back(this->getStateByIndex(x, y - 1));
    }
    return posStates;
}

template<class T>
State<T> *Matrix<T>::getInitialState() {
    return Searchable<T>::getInitialState();
}

template<class T>
Matrix<T>::Matrix(State<T> ***s, int height, int width, int initX, int initY, int goalX, int goalY) {
    this->matrix = s;
    this->height = height;
    this->width = width;
    this->initState = this->getStateByIndex(initX, initY);
    this->goalState = this->getStateByIndex(goalX, goalY);


}

template<class T>
State<T> *Matrix<T>::getStateByIndex(int x, int y) {
//todo
    return nullptr;
}

#endif //PROJB_MATRIX_H
