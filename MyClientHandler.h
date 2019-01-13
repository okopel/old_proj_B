#ifndef PROJB_MYCLIENTHANDLER_H
#define PROJB_MYCLIENTHANDLER_H

#include "./interface/ClientHandler.h"
#include <vector>
#include "searchable/Matrix.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Point.h"

using std::string;
using std::ofstream;
using std::ifstream;
using project::Pointm;


class MyClientHandler : public ClientHandler<Matrix<Pointm>, list<State<Pointm> *> *> {

    vector<Pointm *> parserLine(int line, string s);

    Pointm *specifigPoint(string line) {
        string x, y;
        int delimiter = line.find(",");
        x = line.substr(0, delimiter);
        y = line.substr(delimiter + 1, line.size());
        return new Pointm(stoi(x), stoi(y), 0);
    }

    Matrix<Pointm> *getMatrix(ifstream &input);

public:
    MyClientHandler(Solver<Matrix<Pointm>, list<State<Pointm> *> *> *solver, CacheManager *cacheManager);

    void handleClient(string inputFile, string outputFile) override;


};

void MyClientHandler::handleClient(string inputFile, string outputFile) {

    vector<Matrix<Pointm> *> matrixes;
    string s;
    ifstream input;
    input.open(inputFile);
    if (!input.is_open()) {
        throw "Error in input file";
    }
    ofstream output;
    output.open(outputFile);
    if (!output.is_open()) {
        throw "Error in output file";
    }
    input >> s;
    int numOfGraphs = stoi(s);
    //load all graphs from inputStream
    for (int graphIndex = 0; graphIndex < numOfGraphs; graphIndex++) {
        Matrix<Pointm> *m = this->getMatrix(input);
        matrixes.push_back(m);
    }
    for (auto *tmpMatrix:matrixes) {
        auto ans = this->solver->solve(tmpMatrix);//todo save the answer
    }
}


vector<Pointm *> MyClientHandler::parserLine(int line, string s) {
    vector<Pointm *> vector;
    string buffer;
    int col = 0;
    for (char c:s) {
        if (c == ',') {
            vector.push_back(new Pointm(col, line, stoi(buffer)));
            col++;
            buffer = "";
            continue;
        }
        buffer += c;
    }
    vector.push_back(new Pointm(col, line, stoi(buffer)));
    return vector;
}

Matrix<Pointm> *MyClientHandler::getMatrix(ifstream &istream) {
    string s = "";
    istream >> s;//todo heg,width of h=w?
    int size = stoi(s);
    s = "";
    istream >> s;
    auto *inition = this->specifigPoint(s);
    s = "";
    istream >> s;
    auto *goal = this->specifigPoint(s);
    auto matrix = new State<Pointm> **[size];
    for (int i = 0; i < size; i++) {//get the graph
        auto vector = this->parserLine(i, s);
        matrix[i] = new State<Pointm> *[size];//initon line
        for (int j = 0; j < size; j++) {//get line of matrix
            matrix[i][j] = new State<Pointm>(*vector[j]);
        }
        s = "";
        istream >> s;
    }
    return new Matrix<Pointm>(matrix, size, size, *inition, *goal);
}


MyClientHandler::MyClientHandler(Solver<Matrix<Pointm>, list<State<Pointm> *> *> *solver, CacheManager *cacheManager)
        : ClientHandler<Matrix<Pointm>, list<State<Pointm> *> *>(solver,
                                                                 cacheManager) {

}


#endif //PROJB_MYCLIENTHANDLER_H
