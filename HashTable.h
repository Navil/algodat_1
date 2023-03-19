#ifndef HASH_TABLE
#define HASH_TABLE

#include <string>
#include <vector>

// local includes
#include "Entry.h"
#include "Aktie.h"


using namespace std;

const int ARRAY_SIZE = 1093;

class HashTable{
    private:
        Aktie aktien[ARRAY_SIZE];
        // Methods
        int hashFunction(string s);
        // returns where to insert
        int getInsertionIndex(string s);
        // tries to find, if not, returns -1
        int findByKuerzel(string kuerzel);
        void insertData(vector<vector<string>> data, int insertionIndex);


        //get data from csv and copy it into vector of vectors
        vector<vector<string>> readCSV(string fname);
        //get data of last 30 days from the already parsed CSV
        vector<vector<string>> takeLastMonthData(vector<vector<string>> parsedCSV);

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
        void search();
        void plot();
        HashTable();
};

#endif // HASH_TABLE
