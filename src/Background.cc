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
    rows_ = row;
    columns_ = column;

    for(auto it = alivePosition.begin(); it != alivePosition.end(); ++it){
        backgroundNow_[it->first][it->second].setStatus(Cell::alive);
    }

}

void Background::print(){
    clearScreen();
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

void Background::update(){
    for(int i = 0; i < backgroundNow_.size(); ++i){
        for(int j = 0; j < backgroundNow_[i].size(); ++j){
            if(i - 1 >= 0){
                if(j - 1 >= 0 && backgroundNow_[i-1][j-1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
                if(j + 1 < backgroundNow_[i].size() && backgroundNow_[i-1][j+1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
                if(backgroundNow_[i-1][j].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
            }
            {
                if(j - 1 >= 0 && backgroundNow_[i][j-1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
                if(j + 1 < backgroundNow_[i].size() && backgroundNow_[i][j+1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
            }
            if(i + 1 < backgroundNow_.size()){
                if(j - 1 >= 0 && backgroundNow_[i+1][j-1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
                if(j + 1 < backgroundNow_[i].size() && backgroundNow_[i+1][j+1].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
                if(backgroundNow_[i+1][j].isAlive()){
                    backgroundNext_[i][j].neighborNumAddOne();
                }
            }

            if(backgroundNext_[i][j].neighborNum() == 2 || backgroundNext_[i][j].neighborNum() == 3){
                backgroundNext_[i][j].setStatus(Cell::alive);
            }
            else{
                backgroundNext_[i][j].setStatus(Cell::died);
            }
            
        }
    }

    swap(backgroundNow_, backgroundNext_);
    backgroundNext_ = vector<vector<Cell>>(rows_, vector<Cell>(columns_, Cell()));
}

  

