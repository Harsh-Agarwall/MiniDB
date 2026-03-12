#include "database.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){

    Database db;

    string line;

    while(true){

        cout<<"MiniDB > ";

        getline(cin,line);

        stringstream ss(line);

        string cmd;
        ss>>cmd;

        if(cmd=="INSERT"){

            map<string,string> row;

            string word;

            while(ss>>word){

                int pos = word.find('=');

                string key = word.substr(0,pos);
                string value = word.substr(pos+1);

                row[key] = value;
            }

            db.insert(row);
        }

        else if(cmd=="SELECT"){

            int id;
            ss>>id;

            db.select(id);
        }

        else if(cmd=="DELETE"){

            int id;
            ss>>id;

            db.remove(id);
        }

        else if(cmd=="PRINT"){

            db.print();
        }

        else if(cmd=="EXIT"){
            break;
        }
    }
}