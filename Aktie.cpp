#include <vector>
// we used asciiplotter class found on Github
// https://github.com/joehood/asciiplotter/blob/master/src/asciiplotter.cpp
#include "asciiplotter.h"

#include "Aktie.hpp"


Aktie::Aktie() {
    // Initialize all stocks as empty
    this->kuerzel = "";
    this->name = "";
    this->wkn = "";
    this->isDeleted = false;
    // The entries[30] are automatically initialized as zero with the Entry() constructor
    }

void Aktie::clear() {
    this->kuerzel = "";
    this->name = "";
    this->wkn = "";
    this->isDeleted = false;
    for(int i = 0; i < 30; i++) {
        this->entries[i].clear();
    }
}

// we used asciiplotter class found on Github
// https://github.com/joehood/asciiplotter/blob/master/src/asciiplotter.cpp
void Aktie::plot() {
    AsciiPlotter plotter (this->name, 60, 20);
    plotter.xlabel("time");
    plotter.ylabel("USD");
    // This class requires doubles
    vector<double> schlusskurse;
    vector<double> time;
    for (int i = 0; i < DAYS_SIZE; i++) {
        time.push_back(i);
    }
    for (int i = DAYS_SIZE - 1 ; i >= 0; i--) {
        schlusskurse.push_back(this->entries[i].close);
    }
    plotter.addPlot(time, schlusskurse, "Schlusskurse", '*');
    plotter.show();
}

bool Aktie::isEmpty() {
    if (this->kuerzel == "")
        return true;
    else
        return false;
}

