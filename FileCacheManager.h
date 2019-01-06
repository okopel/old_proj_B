

#ifndef PROJB_FILECACHEMANAGER_H
#define PROJB_FILECACHEMANAGER_H

#include "CacheManager.h"

class FileCacheManager : public CacheManager {
public:
    void saveSolution(Problem *p, Solution *s) override;
};

void FileCacheManager::saveSolution(Problem *p, Solution *s) {//todo

}

#endif //PROJB_FILECACHEMANAGER_H
