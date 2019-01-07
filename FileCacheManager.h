

#ifndef PROJB_FILECACHEMANAGER_H
#define PROJB_FILECACHEMANAGER_H

#include "CacheManager.h"
template<class P, class S>
class FileCacheManager : public CacheManager {
public:
    void saveSolution(P *p, S *s) override;
};

void FileCacheManager::saveSolution(P *p, S *s) {//todo

}

#endif //PROJB_FILECACHEMANAGER_H
