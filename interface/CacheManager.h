
#ifndef PROJB_CACHEMANAGER_H
#define PROJB_CACHEMANAGER_H
#include <map>
#include <string>
#include <stdio.h>

using std::string;
using std::map;


class CacheManager {
    map<string, string> solMap;
public:
    virtual bool isSolved(string p) {
        return solMap.count(p) != 0;
    }

    virtual string getSolution(string p) {
        return solMap[p];
    }

    virtual void saveSolution(string p, string s) = 0;
};

#endif //PROJB_CACHEMANAGER_H
