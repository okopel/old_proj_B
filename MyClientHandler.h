#ifndef PROJB_MYCLIENTHANDLER_H
#define PROJB_MYCLIENTHANDLER_H

#include "./interface/ClientHandler.h"
#include <vector>
#include "searchable/Matrix.h"
#include <string>
#include <stdio.h>

using std::string;

template<class P, class S>
class MyClientHandler : public ClientHandler<P, S> {
    vector<int> parserLine(string s);

    Matrix<int> *getMatrix(istream istream);

public:
    void handleClient(istream istream, ostream ostream) override;

    MyClientHandler(Solver<P, S> *solver, CacheManager<P, S> *cacheManager);

};


#endif //PROJB_MYCLIENTHANDLER_H
