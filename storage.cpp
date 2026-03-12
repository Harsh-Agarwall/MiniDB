#include "storage.h"
#include <fstream>
#include <sstream>

using namespace std;

void saveToFile(map<string,string> row){

    ofstream file("data.txt",ios::app);

    for(auto &p:row)
        file<<p.first<<"="<<p.second<<",";

    file<<endl;

    file.close();
}

void loadFromFile(RBTree &index){

    ifstream file("data.txt");

    string line;

    while(getline(file,line)){

        map<string,string> row;

        stringstream ss(line);

        string pair;

        while(getline(ss,pair,',')){

            int pos = pair.find('=');

            if(pos == string::npos) continue;

            string key = pair.substr(0,pos);
            string value = pair.substr(pos+1);

            row[key] = value;
        }

        if(row.count("id")){

            int id = stoi(row["id"]);

            index.insert(id,row);
        }
    }

    file.close();
}