#ifndef DATABASE_H
#define DATABASE_H

#include "rbtree.h"

class Database{

private:
    RBTree index;

public:
    Database();

    void insert(std::map<std::string,std::string>);
    void select(int);
    void remove(int);
    void print();
};

#endif