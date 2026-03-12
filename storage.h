#ifndef STORAGE_H
#define STORAGE_H

#include <map>
#include <string>
#include "rbtree.h"

void saveToFile(std::map<std::string,std::string>);
void loadFromFile(RBTree &index);

#endif