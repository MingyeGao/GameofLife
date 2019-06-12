#include <assert.h>

#include <vector>
#include <fstream>
#include <cstdio>
#include <string>
#include <set>

#include "Background.h"
#include "Options.h"
#include "Cell.h"

using namespace std;

Background::Background(Options &options):
  circleTime(options.circleTime){
    ifstream ifile(options.fileName);
    if(!ifile.good()){
        perror("config file open failed");
        exit;
    }
    int column = -1, row = 0;
    string tmp;
    typedef set<pair<int, int>> AlivePosition;
    AlivePosition alivePosition;
    while(ifile >> tmp){
        if(column == -1){
            column = tmp.size();
        }
        else{
            assert(tmp.size() == column);
        }
        for(int i = 0; i < column; ++i){
            assert(tmp[i] == '1' || tmp[i] == '0');
            if(tmp[i] == '1'){
                alivePosition.insert(pair<int, int>(row, i));
            }
        }
        ++row;
    }

    backgroundNext_ = vector<vector<Cell>>(row, vector<Cell>(column, Cell()));
    backgroundNow_ = vector<vector<Cell>>(row, vector<Cell>(column, Cell()));

    for(auto it = alivePosition.begin(); it != alivePosition.end(); ++it){
        backgroundNow_[it->first][it->second].setStatus(Cell::alive);
    }

}

void Background::print(){
    printf("\033[2J");
    for(int i = 0; i < backgroundNow_.size(); ++i){
        for(int j = 0; j < backgroundNow_[i].size(); ++j){
            if(backgroundNow_[i][j].isAlive()){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
  

