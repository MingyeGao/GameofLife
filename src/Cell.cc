#include "Cell.h"

Cell::Cell():
    neighborNum_(0),
    status_(died){};


void Cell::setStatus(status s){
    status_ = s;
}

void Cell::neighborNumAddOne(){
    ++neighborNum_;
}