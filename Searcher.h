

#ifndef PROJB_SEARCHER_H
#define PROJB_SEARCHER_H

#include <list>
#include "Solution.h"
#include "Searchable.h"
#include "Isearcher.cpp"

//abstract
template<class T>
class Searcher : public Isearcher<T> {
protected:
    list<State<T> *> stateList;
    State<T> *initial;
    State<T> *goal;
public:
    Solution *search(Searchable<T> *searchable) = 0;

    int getNumberOfNodesEvaluated();
};


#endif //PROJB_SEARCHER_H
