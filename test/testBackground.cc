#include "../src/Background.h"
#include "../src/Options.h"
#include "../src/parseCommandLine.h"
#include <cstdio>

int main(int argc, char* argv[]){
    Options option;
    parseCommandLine(argc, argv, option);
    Background background1(option);
    background1.print();
    background1.update();
    getchar();
    background1.print();
    

    return 0;
}