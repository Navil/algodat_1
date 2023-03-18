#include "HashTable.h"


int main() {
    HashTable table;

    string input;

    while(input != "QUIT"){
        cout << "Type a command. To stop type exit." << endl;
        cin >> input;

        if(input == "IMPORT"){
            table.import();
        }else if(input == "ADD"){
            table.add();
        }else if(input == "SAVE"){
            table.save();
        }else if(input == "SEARCH"){
            table.search();
        }

    }
    return 0;
}



