#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
struct Entry{
    Entry();
    Entry(string date, string open, string high, string low, string close, string volume, string adjClose){
        this->date = date;
        this->open = stof(open);
        this->high = stof(high);
        this->low = stof(low);
        this->close = stof(close);
        this->volume = stof(volume);
        this->adjClose = stof(adjClose);
    }
    string date;
    float open;
    float high;
    float low;
    float close;
    float volume;
    float adjClose;
};

struct Aktie{
    Entry entries[30];
    string kuerzel;
    string name;
    string wkn;
};

class HashTable{
    struct Aktie aktien[1093];

    int hash_function(const std::string& s) {
        int hash_val = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            hash_val += static_cast<int>(s[i]) * pow(31, n-1-i);
        }
        return hash_val%1093;
    }

    Entry* createEntryFromCSV(vector<vector<string>> content){
        Entry entries[30];
        for(int i=0;i<content.size();i++)
        {
            entries[i] = Entry(content[i][0], content[i][1], content[i][2], content[i][3], content[i][4], content[i][5], content[i][6] );
            //Row i in the csv
            for(int j=0;j<content[i].size();j++)
            {

                cout<<content[i][j]<<" ";
            }
            cout<<"\n";
        }
        return entries;
    }

public:
    //Functions for ADD, DEL, IMPORT, ...
    void import(){
        string kuerzel;
        cout<<"Enter the Kuerzel:"<<endl;
        cin >> kuerzel;

        string fname;
        cout<<"Enter the path to the file: ";
        cin>>fname;

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file (fname, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        else
            cout<<"Could not open the file\n";

        Entry* entries = createEntryFromCSV(content);
        struct Aktie* aktie = &aktien[hash_function(kuerzel)];
        aktie->entries = entries;

    }
};

