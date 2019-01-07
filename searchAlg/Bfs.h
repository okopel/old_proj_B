
#ifndef PROJB_BFS_H
#define PROJB_BFS_H

#include "../Searcher.h"
#include "../State.h"
#include <functional>
#include <queue>
#include <vector>

using namespace std;

template<class T, class P, class S>
class Bfs : public Searcher<T,S> {
public:
    S *search(Searchable<T> *searchable) override {
        priority_queue<State<T> *> open;

        // list<State<T> *> open;
        open.push_back(this->initial);
        list<State<T> *> closed;

        while (!open.empty()) {
            State<T> *s = open.pop_back();
            closed.push_back(s);
            if (s->equal(this->goal)) {
                list<State<T> *> path;
                while (!s->equal(this->initial)) {
                    path.push_back(s);
                    s = s->getCameFrom();
                }
                return s;
            }
            vector<State<T> *> poss = searchable->getAllPossibleStates(s);
            for (State<T> *state:poss) {
                bool isInOpen = false;
                bool isInClose = false;
                for (auto clos:closed) {
                    if (clos == state) {
                        isInClose = true;
                        break;
                    }
                }
                for (auto op:open) {
                    if (op == state) {
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
