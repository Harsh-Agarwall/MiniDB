#include "database.h"
#include "storage.h"
#include <iostream>

Database::Database(){
    loadFromFile(index);
}

void Database::insert(std::map<std::string,std::string> row){

    int id = stoi(row["id"]);

    index.insert(id,row);

    saveToFile(row);

    std::cout<<"Inserted\n";
}

void Database::select(int id){

    auto row = index.search(id);

    if(row.empty()){
        std::cout<<"Not Found\n";
        return;
    }

    for(auto &p:row)
        std::cout<<p.first<<"="<<p.second<<" ";

    std::cout<<std::endl;
}

void Database::remove(int id){
    index.remove(id);
}

void Database::print(){
    index.print();
}