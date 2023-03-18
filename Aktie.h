#include <string>
#include "Entry.h"

using namespace std;

const int DAYS_SIZE = 30;



struct Aktie{
    Aktie();

    Entry entries[DAYS_SIZE];
    string kuerzel;
    string name;
    string wkn;
    bool isDeleted;
    bool isEmpty();
    void clear();
    void plot();
};
