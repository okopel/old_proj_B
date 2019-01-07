

#ifndef PROJB_SEARCHER_H
#define PROJB_SEARCHER_H

#include <list>
#include "Searchable.h"
#include "Isearcher.cpp"

//abstract
template<class T,class S>
class Searcher : public Isearcher<T,S> {
protected:
    list<State<T> *> stateList;
    State<T> *initial;
    State<T> *goal;
public:
    virtual S *search(Searchable<T> *searchable) = 0;

    int getNumberOfNodesEvaluated();
};


#endif //PROJB_SEARCHER_H
