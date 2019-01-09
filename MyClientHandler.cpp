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
        s = "";
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
        //int height=stoi(s);        //int width;
        State<int> ***matrix = new State<int> **[size];
        //while (s != "end") {
        for (int i = 0; i < size; i++) {//get the graph
            vector<int> vector = this->parserLine(s);
            matrix[i] = new State<int> *[size];
            for (int j = 0; j < size; j++) {//get line of matrix
                matrix[i][j] = new State<int>(vector[j]);
            }
            i++;
            s = "";
            istream >> s;
        }
        ostream << s;
        Matrix<int> *myMatrix = new Matrix<int>(matrix, size, size, initionX, initionY, goalX, goalY);
        matrixes.push_back(myMatrix);
    }//enf of geting all the graphs.
    //for (Matrix<int> *matrix:matrixes) {
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
    return vector;
}
