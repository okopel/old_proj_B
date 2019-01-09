
#ifndef PROJB_ISEARCHER_H
#define PROJB_ISEARCHER_H

#include <string>
#include "Solver.h"
#include <stdio.h>

using std::string;

//interface
template<class T>
class Isearcher : public Solver<Searchable<T>, list<State<T> *>> {
protected:

public:

    list<State<T> *> *solve(Searchable<T> *p) override {
        State<T> *goal = this->search(p);
        list<State<T> *> path;
        while (goal != nullptr) {
            path.push_back(goal);
            goal = goal->getCameFrom();
        }
        return path;
    }

    virtual State<T> *search(Searchable<T> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;

};


#endif //PROJB_ISEARCHER_H
