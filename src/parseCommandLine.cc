#include <unistd.h>

#include <string>

#include "Options.h"

void parseCommandLine(int argc, char *argv[], Options &options){
    int opt;
    while((opt = getopt(argc, argv, "t:f:")) != -1){
        switch(opt){
            case 't':
                options.circleTime = atoi(optarg);
                break;
            case 'f':
                options.fileName = string(optarg);
                break;
            default:
                break;
        }
    }
}