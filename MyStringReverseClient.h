

#ifndef PROJB_MYSTRINGREVERSECLIENT_H
#define PROJB_MYSTRINGREVERSECLIENT_H

#include "interface/CacheManager.h"
#include "interface/ClientHandler.h"
#include <stdio.h>
#include <iostream>

using std::cin;
using std::string;


class MyStringClient : public ClientHandler<string, string> {
public:
    MyStringClient(Solver<string, string> *solver, CacheManager *cacheManager) : ClientHandler<string, string>(solver,
                                                                                                               cacheManager) {

    }

    void x() {
        string s;
        cout << "enter:" << endl;
        cin >> s;
        cout << *(this->solver->solve(s));
    }

    void handleClient(string in, string out) override {
        string s;
        cout << "enter:" << endl;
        cin >> s;
        cout << *this->solver->solve(s);
    }

};

#endif //PROJB_MYSTRINGREVERSECLIENT_H
