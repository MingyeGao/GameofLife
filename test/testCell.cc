#include "../src/Cell.h"
#include <cstdio>

int main(){
    Cell testCell;
    printf("%d", testCell.neighborNum());
    if(!testCell.isAlive()){printf("die!");}

    return 0;
}