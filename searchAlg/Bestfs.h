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
using std::begin;
using std::end;

template<class P, class T>
class Bestfs : public Searcher<P, T> {
    bool isInOpen(State<T> state, priority_queue<State<T> *> open) {
        while (!open.empty()) {
            auto openStae = open.top();
            if (state == openStae) {
                return true;
            }
            open.pop();
        }
        return false;
    }

public:
    Bestfs() : Searcher<P, T>() {
        //  cout << typeid(T).name() << endl;
        //cout << typeid(Searcher<T>).name() << endl;
    };

    int getNumberOfNodesEvaluated() override {
        return 0;
    }

    virtual State<T> *search(Searchable<T> *searchable) override {
        priority_queue<State<T> *> open;
        // list<State<T> *> open;
        open.push(this->initial);
        list<State<T> *> closed;
        while (!open.empty()) {
            State<T> *s = open.top();
            open.pop();
            closed.push_back(s);
            if (s == this->goal) {
                return s;
            }
            vector<State<T> *> *possibleSates = searchable->getAllPossibleStates(s);
            for (int i = 0; i < possibleSates->size(); i++) {
                //for (auto state:possibleSates) {
                bool isInOpen = false;
                bool isInClose = false;
                for (auto vertex:closed) {
                    if (*vertex == (possibleSates->at(i))) {
                        isInClose = true;
                        break;
                    }
                }
                isInOpen = this->isInOpen(*possibleSates->at(i), open);

                if (!isInClose && !isInOpen) {
                    possibleSates->at(i)->setCameFrom(s);
                    open.push(possibleSates->at(i));
                } else {
                    if (possibleSates->at(i)->getCost() > (s->getCost() + 1)) {
                        possibleSates->at(i)->setCost(s->getCost() + 1);
                        possibleSates->at(i)->setCameFrom(s);
                    }
                    if (!isInOpen) {
                        open.push(possibleSates->at(i));
                    }
                    //todo Otherwise, adjust its priority in OPEN??
                }
            }


        }

    }
};


#endif //PROJB_BFS_H
