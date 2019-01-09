#include "MyClientHandler.h"
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include "interface/State.h"
#include "searchable/Matrix.h"
#include "interface/Isearcher.h"

using std::string;

template<class P, class S>
void MyClientHandler<P, S>::handleClient(istream istream, ostream ostream) {
    vector<Matrix<int> *> matrixes;
    string s;
    istream >> s;
    int numOfGraphs = stoi(s);
    //load all graphs from inputStream
    for (int graphIndex = 0; graphIndex < numOfGraphs; graphIndex++) {
        matrixes.push_back(this->getMatrix(istream));
    }
    for (Searchable<int> *tmpMatrix:matrixes) {
        this->solver->solve(tmpMatrix);
    }
}

template<class P, class S>
vector<int> MyClientHandler<P, S>::parserLine(string s) {
    vector<int> vector;
    string buffer;
    for (char c:s) {
        if (c == ',') {
            vector.push_back(stoi(buffer));
            buffer = "";
            continue;
        }
        buffer += c;
    }
    vector.push_back(stoi(buffer));
    return vector;
}

template<class P, class S>
Matrix<int> *MyClientHandler<P, S>::getMatrix(istream istream) {
    string s = "";
    istream >> s;//todo heg,width of h=w?
    int size = stoi(s);
    s = "";
    istream >> s;
    vector<int> pair = this->parserLine(s);
    int initionX = pair[0];
    int initionY = pair[1];
    s = "";
    istream >> s;
    pair = this->parserLine(s);
    int goalX = pair[0];
    int goalY = pair[1];
    State<int> ***matrix = new State<int> **[size];
    for (int i = 0; i < size; i++) {//get the graph
        vector<int> vector = this->parserLine(s);
        matrix[i] = new State<int> *[size];//initon line
        for (int j = 0; j < size; j++) {//get line of matrix
            matrix[i][j] = new State<int>(vector[j]);
        }
        s = "";
        istream >> s;
    }
    return new Matrix<int>(matrix, size, size, initionX, initionY, goalX, goalY);
}
