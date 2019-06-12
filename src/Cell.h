#ifndef CELL_H
#define CELL_H

#include <cstdio>

class Cell{
public:
    enum status{alive, died};
    Cell();
    void setStatus(status s);
    void setNeighborNum();
    int neighborNum(){return neighborNum_;}
    bool isAlive(){return status_ == alive;}
private:
    unsigned int neighborNum_;
    status status_;

};


#endif // CELL_H