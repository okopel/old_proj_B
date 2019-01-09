
#ifndef PROJB_BFS_H
#define PROJB_BFS_H

#include "../interface/Searcher.h"
#include "../interface/State.h"
#include <functional>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <list>

using std::string;
using std::priority_queue;
using std::list;

template<class T>
class Bestfs : public Searcher<T> {
public:
    virtual State<T> *search(Searchable<T> *searchable) override {
        priority_queue<State<T> *> open;
        // list<State<T> *> open;
        open.push(this->initial);
        list<State<T> *> closed;
        while (!open.empty()) {
            State<T> *s = open.top();
            open.pop();
            closed.push_back(s);
            if (s->equal(this->goal)) {
//                list<State<T> *> path;
//                while (!s->equal(this->initial)) {
//                    path.push_back(s);
//                    s = s->getCameFrom();
//                }
                return s;
            }
            vector<State<T> *> possibleSates = searchable->getAllPossibleStates(s);
            for (State<T> *state:possibleSates) {
                bool isInOpen = false;
                bool isInClose = false;
                for (auto &vertex:closed) {
                    if (vertex == state) {
                        isInClose = true;
                        break;
                    }
                }
                for (auto &vertex:open) {
                    if (vertex == state) {
                        isInOpen = true;
                        break;
                    }
                }
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
                }
            }


        }

    }
};


#endif //PROJB_BFS_H
