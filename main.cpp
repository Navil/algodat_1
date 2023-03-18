#include "HashTable.h"
#include <iostream>

int main() {
    HashTable table;

    string input;

    while(input != "QUIT"){
        cout << "Type a command. To stop type QUIT." << endl;
        cin >> input;

        if(input == "IMPORT"){
            table.import();
        }else if(input == "ADD"){
            table.add();
        }else if(input == "SAVE"){
            table.save();
        }else if(input == "LOAD"){
            table.load();
        }else if(input == "SEARCH"){
            table.search();
        }else if(input == "PLOT"){
            table.plot();
        } else if(input == "DEL"){
            table.del();
        }
    }
    return 0;
}



