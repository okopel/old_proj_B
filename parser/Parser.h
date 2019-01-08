
#ifndef PROJB_PARSER_H
#define PROJB_PARSER_H


#include <string>

using std::string;

//interface
template<class P, class S>
class Parser {
public:
    virtual string probToString(P *p) = 0;

    virtual string solToString(S *s) = 0;

    virtual S *stringToSol(string s) = 0;

    virtual P *stringToPro(string s) = 0;
};

#endif //PROJB_PARSER_H
