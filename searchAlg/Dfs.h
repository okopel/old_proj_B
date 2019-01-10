
#ifndef PROJB_DFS_H
#define PROJB_DFS_H

#include "../interface/Searcher.h"
#include "../interface/State.h"
#include <functional>
#include <queue>
#include <vector>
#include "Dfs.h"

using namespace std;

template<class T>
class Dfs : public Searcher<T> {
public:
    virtual State<T> *search(Searchable<T> *searchable) override {
        list<State<T>> states = searchable.getAllStates();
        list<State<T>> blacks;
        list<State<T>> grays;
        State<t> begin = this->initial;
        for (auto &s : searchable.getAllPossibleStates(begin);) {
            bool isWhite = (find(grays.begin()), grays.end(), s) != grays.end();
            if (isWhite) {
                this->visit(s, blacks, grays, searchable);
            }
        }

    }

    template<class T>
    void DFS<T>::visit(State<T> state, list<State<T>> blacks, list<State<T>> grays, Searchable<T> searchable) {
        grays.push_back(state);
        // if state is goal state
        if (searchable.getGoalState().equals(state)) {
            return state;
        }

        list<State<T>> adj = searchable.getAllPossibleStates(state);


        for (auto &a : adj) {
            bool isWhite = (find(grays.begin()), grays.end(), a) != grays.end();
            if (isWhite) {
                a.setCameFrom(state); // compiler doesnt recognise. weird...
                this->visit(a, blacks, grays, searchable);
            }
        }
        blacks.push_back(state);
    }


};
#endif
