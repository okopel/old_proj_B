#include "Matrix.h"


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
    vector <State<T>> posStates;
    if (x < this->width) {//rohav
        posStates.push_back(this->getStateByIndex(x + 1, y));
    }
    if (x > 0) {
        posStates.push_back(this->getStateByIndex(x - 1, y));
    }
    if (y < this->height) {
        posStates.push_back(this->getStateByIndex(x, y + 1));
    }
    if (y > 0) {
        posStates.push_back(this->getStateByIndex(x, y - 1));
    }
    return posStates;
}

template<class T>
State<T> *Matrix<T>::getInitialState() {
    return Searchable<T>::getInitialState();
}

template<class T>
Matrix<T>::Matrix(State<T> **s, int height, int width) {
    this->matrix = s;
    this->height = height;
    this->width = width;


}
