#include "HashTable.h"


int main() {
    HashTable table;

    string input;

    while(input != "exit"){
        cout << "Type a command. To stop type exit." << endl;
        cin >> input;

        if(input == "import"){
            table.import();
        }

    }
    return 0;
}



