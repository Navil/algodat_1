

#include <iostream>
// local includes
#include "Entry.h"

Entry::Entry() {
    this->date = "";
    this->open = 0;
    this->high = 0;
    this->low = 0;
    this->close = 0;
    this->volume = 0;
    this->adjClose = 0;}


void Entry::clear() {
    this->date = "";
    this->open = 0;
    this->high = 0;
    this->low = 0;
    this->close = 0;
    this->volume = 0;
    this->adjClose = 0;
}

void Entry::set(string date, string open, string high, string low, string close, string volume, string adjClose){
    this->date = date;
    // std::stof -> converts string to float
    this->open = stof(open);
    this->high = stof(high);
    this->low = stof(low);
    this->close = stof(close);
    this->volume = stof(volume);
    this->adjClose = stof(adjClose);
}


void Entry::print(){
    cout << date << +", " << open << ", " << high << ", " << low << ", " << close << ", " << volume << ", " << adjClose << endl;
}
