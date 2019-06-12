#include "../src/parseCommandLine.h"
#include "../src/Options.h"

#include <cstdio>

using namespace std;

int main(int argc, char* argv[]){
    Options option;
    parseCommandLine(argc, argv, option);
    printf("%d %s", option.circleTime, option.fileName.c_str());

    return 0;
}