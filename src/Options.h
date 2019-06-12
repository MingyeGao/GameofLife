#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

using namespace std;

class Options{
public:
    Options():circleTime(1000), fileName("config"){};
    int circleTime;
    string fileName;
};

#endif //OPTIONS_H