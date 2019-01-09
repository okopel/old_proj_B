#ifndef PROJB_MYCLIENTHANDLER_H
#define PROJB_MYCLIENTHANDLER_H

#include "./interface/ClientHandler.h"
#include <vector>
#include "searchable/Matrix.h"

using std::string;

template<class P, class S>
class MyClientHandler : public ClientHandler<P, S> {
    vector<int> parserLine(string s);

    Matrix<int> *getMatrix(istream istream);

public:
    void handleClient(istream istream, ostream ostream) override;

};


#endif //PROJB_MYCLIENTHANDLER_H
