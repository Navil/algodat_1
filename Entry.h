#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

struct Entry {
    Entry();
    void set(string date, string open, string high, string low, string close, string volume, string adjClose);

    string date;
    float open;
    float high;
    float low;
    float close;
    float volume;
    float adjClose;
    void clear();

    void print();
};


#endif // ENTRY_H
