#ifndef PROJB_BFS_H
#define PROJB_BFS_H

#include "../interface/Searcher.h"
#include "../interface/State.h"
#include <functional>
#include <queue>
#include <vector>

using namespace std;

template<class T>
class Bfs : public Searcher<T> {
public:
    virtual State<T> *search(Searchable<T> *searchable) override {
        priority_queue<State<T> *> notVisited;
        notVisited.push_back(this->initial);
        list<State<T> *> visited;

        while (!notVisited.empty()) {
            State<T> *s = notVisited.pop_back();
            if (s->equal(this->goal)) {
                list<State<T> *> path;
                return s;
            }
            vector<State<T> *> possibleStates = searchable->getAllPossibleStates(s);
            for (State<T> *state : possibleStates) {
                // mark all states as visited or not
                bool childVisited = false;
                for (auto &vertex : closed) {
                    if (vertex == state) {
                        isInClose = true;
                        break;
                    }
                }
                //  TODO delete due to open complement close
                /*bool childNotVisited = false;
                for (auto &vertex:open) {
                    if (vertex == state) {
                        isInOpen = true;
                        break;
                    }
                }*/
                if (!childVisited) {
                    visited.push_back(state);
                    notVisited.pop_back(state);
                }
/*
                if (!isInClose && !isInOpen) {
                    state->setCameFrom(s);
                    open.push_back(state);
                } else {
                    if (state->getCost() > (s->getCost() + 1)) {
                        state->setCost(s->getCost() + 1);
                        state->setCameFrom(s);
                    }
                    if (!isInOpen) {
                        open.push_back(state);

                    }
                    //todo Otherwise, adjust its priority in OPEN??
                }*/
            }
        }
    }
};

#endif