#ifndef PROJB_MYCLIENTHANDLER_H
#define PROJB_MYCLIENTHANDLER_H

#include "./interface/ClientHandler.h"
#include <vector>

using std::string;

template<class P, class S>
class MyClientHandler : public ClientHandler<P, S> {
    vector<int> parserLine(string s);

public:
    void handleClient(istream istream, ostream ostream) override;

};


#endif //PROJB_MYCLIENTHANDLER_H
