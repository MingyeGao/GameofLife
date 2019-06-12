#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>

#include "Options.h"
#include "Cell.h"

using namespace std;

class Background{
public:
    Background(Options &options);
    void start();
public:
    vector<vector<Cell> > backgroundNow_;
    vector<vector<Cell> > backgroundNext_;
    void update();
    void print();
    void clearScreen(){system("cls");}
    int circleTime_;
    int rows_;
    int columns_;

};

#endif //BACKGROUND_H