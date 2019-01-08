#include "StringReverserParser.h"

#define PROB_START_SIGN "@p:"
#define END_SIGN "$ "
#define SOL_START_SIGN "#s:"
using std::string;

string StringReverserParser::probToString(string *p) {
    return PROB_START_SIGN + *p + END_SIGN;
}

string StringReverserParser::solToString(string *s) {
    return SOL_START_SIGN + *s + END_SIGN;
}

string *StringReverserParser::stringToSol(string s) {
    return nullptr;//todo
}

string *StringReverserParser::stringToPro(string s) {
    return nullptr;//todo
}
