

#include "HashTable.cpp"




int main() {
    HashTable table = HashTable();

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



