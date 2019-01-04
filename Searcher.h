

#ifndef PROJB_SEARCHER_H
#define PROJB_SEARCHER_H

#include "Solution.h"
#include "Searchable.h"

class Searcher {

    Solution *search(Searchable *searchable);

    int getNumberOfNodesEvaluated();
};


#endif //PROJB_SEARCHER_H
