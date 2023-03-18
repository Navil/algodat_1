#ifndef HASH_TABLE
#define HASH_TABLE

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

struct Entry {
    Entry();
    Entry(string date, string open, string high, string low, string close, string volume, string adjClose);

    string date;
    float open;
    float high;
    float low;
    float close;
    float volume;
    float adjClose;
    void clear();
};

struct Aktie{
    Aktie();

    Entry entries[30];
    string kuerzel;
    string name;
    string wkn;
    void clear();

};

class HashTable{
    private:
        Aktie aktien[1093];
        // Methods
        int hash_function(const string& s);
        int getInsertionIndex(string s);

        //get data from csv and copy it into vector of vectors
        vector<vector<string>> readCSV(string fname);
        //get data of last 30 days from the already parsed CSV
        vector<vector<string>> takeLastMonthData(vector<vector<string>> parsedCSV);

        //search function
        bool isEmpty(int index);
        // SAVE/LOAD related
        string aktieToStringLine(int index);
        void importAktieFromStringLine(string line);


    public:
        //Functions for ADD, DEL, IMPORT, ...
        void save();
        void load();
        void add();
        void del();
        void import();
        HashTable();

        //TESTING
        void readCSVdebug(string fname);


};

#endif // HASH_TABLE
