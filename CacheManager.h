
#ifndef PROJB_CACHEMANAGER_H
#define PROJB_CACHEMANAGER_H

#include "Problem.h"
#include "Solution.h"
#include <map>

using namespace std;

class CacheManager {
    map<Problem *, Solution *> solMap;
public:
    bool isSolved(Problem *p) {
        return solMap.count(p) != 0;
    }

    Solution *getSolution(Problem *p) {
        return solMap[p];
    }

    virtual void saveSolution(Problem *p, Solution *s) = 0;
};

#endif //PROJB_CACHEMANAGER_H
