#include "../src/Cell.h"
#include <cstdio>

int main(){
    Cell testCell;
    printf("%d\n", testCell.neighborNum());
    if(!testCell.isAlive()){printf("die!\n");}
    testCell.neighborNumAddOne();
    printf("%d\n", testCell.neighborNum());
    
    return 0;
}