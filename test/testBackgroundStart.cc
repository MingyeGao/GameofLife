#include "../src/Background.h"
#include "../src/Options.h"
#include "../src/parseCommandLine.h"
#include <cstdio>

int main(int argc, char* argv[]){
    Options option;
    parseCommandLine(argc, argv, option);
    Background background(option);
    background.start();
    

    return 0;
}