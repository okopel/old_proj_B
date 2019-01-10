

#ifndef PROJB_FILECACHEMANAGER_H
#define PROJB_FILECACHEMANAGER_H

#include "../interface/CacheManager.h"
#include <stdio.h>
#include <string>

using std::string;

class FileCacheManager : public CacheManager {
public:
    bool isSolved(string p) override {
        return CacheManager::isSolved(p);
    }

    string getSolution(string p) override {
        return CacheManager::getSolution(p);
    }

    void saveSolution(string p, string s) override {
        //todo
    }
};


#endif //PROJB_FILECACHEMANAGER_H
