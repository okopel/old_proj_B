
#ifndef PROJB_ISEARCHER_H
#define PROJB_ISEARCHER_H

//interface
template<class T>
class Isearcher {
protected:

public:
    Solution *search(Searchable<T> *searchable) = 0;

    int getNumberOfNodesEvaluated() = 0;

};



#endif //PROJB_ISEARCHER_H
