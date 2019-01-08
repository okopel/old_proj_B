

#ifndef PROJB_STRINGREVERSERPARSER_H
#define PROJB_STRINGREVERSERPARSER_H

#include "Parser.h"

class StringReverserParser : public Parser<string, string> {
public:
    string probToString(string *p) override;

    string solToString(string *s) override;

    string *stringToSol(string s) override;

    string *stringToPro(string s) override;
};


#endif //PROJB_STRINGREVERSERPARSER_H
