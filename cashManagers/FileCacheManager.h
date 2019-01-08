

#ifndef PROJB_FILECACHEMANAGER_H
#define PROJB_FILECACHEMANAGER_H

#include "../interface/CacheManager.h"

template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
public:
    void saveSolution(P *p, S *s) override {
        //todo
    }
};


#endif //PROJB_FILECACHEMANAGER_H
