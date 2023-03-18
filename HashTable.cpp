#include "HashTable.h"


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

Entry::Entry(string date, string open, string high, string low, string close, string volume, string adjClose){
    this->date = date;
    // std::stof -> converts string to float
    this->open = stof(open);
    this->high = stof(high);
    this->low = stof(low);
    this->close = stof(close);
    this->volume = stof(volume);
    this->adjClose = stof(adjClose);
}


Aktie::Aktie() {
    // Initialize all stocks as empty
    this->kuerzel = "";
    this->name = "";
    this->wkn = "";
    // The entries[30] are automatically initialized as zero with the Entry() constructor
    }


void Aktie::clear() {
    this->kuerzel = "";
    this->name = "";
    this->wkn = "";
    for(int i = 0; i < 30; i++) {
        this->entries[i].clear();
    }
}

int HashTable::hashFunction(const std::string& s) {
    int hash_val = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        // static_cast<int> to get the ASCII number of the char s[i]
        hash_val += static_cast<int>(s[i]) * pow(31, n-1-i);
        }
    // Take the modulus to restrict the values from 0 to 1092
    return hash_val%ARRAY_SIZE;
}

int HashTable::getInsertionIndex(string kuerzel) {
    int index = hashFunction(kuerzel);
    int tries = 0;
    int base = 1;
    while(tries < ARRAY_SIZE){
        string currentKuerzel = aktien[index].kuerzel;
        if(currentKuerzel.empty()){
            cout << "Empty element found at index: "<<index<<endl;
            return index;
        }else{
            index = (index + (base*base))%ARRAY_SIZE;
            base++;
        }
        tries ++;
    }
    throw range_error( "Gave up looking for insertion index after 1000 tries." );
}

int HashTable::findByIndex(string kuerzel) {
    int index = hashFunction(kuerzel);
    int tries = 0;
    int base = 1;
    while(tries < ARRAY_SIZE){
        string currentKuerzel = aktien[index].kuerzel;
        if(currentKuerzel == kuerzel){
            cout << "Kuerzel found at index: "<<index<<endl;
            return index;
        }else{
            index = (index + (base*base))%ARRAY_SIZE;
            base++;
        }
        tries ++;
    }
    throw range_error( "Gave up looking for kuerzel after 1000 tries." );
}

void insertData(vector<vector<string>> data, int insertionIndex){
    // TODO
}

HashTable::HashTable() {}



//get data from csv and copy it into vector of vectors
vector<vector<string>> HashTable::readCSV(string fname){
    vector<vector<string>> output;
    vector<string> row;
    string line, word;

    // boilerplate code to read csv file
    fstream file (fname, ios::in);
    if(file.is_open())
    {
        // get line populates the variable line with the data in the file
        while(getline(file, line))  // loops until there are no more lines
        {
            row.clear();

            stringstream str(line);
            // get line takes each comma separated word from the str(line) and copies it in word
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            output.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    return output;
}

//get data of last 30 days from the already parsed CSV
vector<vector<string>> HashTable::takeLastMonthData(vector<vector<string>> parsedCSV){

    vector<vector<string>> output;
    //to take last 30 days data
    int finalIndex = parsedCSV.size() - 30;

    for(int i = parsedCSV.size() -1; i >= finalIndex; --i){
        output.push_back(parsedCSV[i]);
    }
    return output;

}

//Functions for ADD, DEL, IMPORT, ...
bool HashTable::isEmpty(int index) {
        //TODO
    return false;
}

string HashTable::aktieToStringLine(int index) {
    // TODO
    return "";
}

void  HashTable::importAktieFromStringLine(string line) {
    // TODO
}
void  HashTable::save(){
    string fname;
    cout<<"Enter filename: ";
    cin>>fname;
    // TODO open file
    // use aktietostringline on the non-empty aktie to populate file
}
void  HashTable::load(){
    string fname;
    cout<<"Enter filename: ";
    cin>>fname;
    // TODO open file and read it line by line
    // use importaktiefromStringLine to load data
}
void  HashTable::del() {

    string kuerzel;
    cout<<"Enter Kuerzel: ";
    cin>>kuerzel;

    int toDelete = getInsertionIndex(kuerzel);

    if (isEmpty(toDelete) == true){
        return;
    }
    else {
         this->aktien[toDelete].clear();
    }
}

void HashTable::add(){

    string name;
    string kuerzel;
    string wkn;

    cout<<"Enter the name of the share: ";
    cin>> name;
    cout<<"Enter the Kuerzel: ";
    cin>> kuerzel;
    cout<<"Enter the name of the WKN: ";
    cin>> wkn;

    int indexToInsert = getInsertionIndex(kuerzel);
    this->aktien[indexToInsert].kuerzel = kuerzel;
    this->aktien[indexToInsert].name = name;
    this->aktien[indexToInsert].wkn = wkn;
    cout << "Successfully added."<<endl;
}

void HashTable::import(){
    // 0: Ask for kuerzel and filename
    string kuerzel;
    cout<<"Enter the Kuerzel:"<<endl;
    cin >> kuerzel;

    // 1: Get insertion index
    int index = findByIndex(kuerzel);
    // 2: Read the relevant CSV rows
    vector<vector<string>> content = readCSV(kuerzel+".csv");
    // 3: Insert data in the corresponding index
    insertData(content, index);

}
//TESTING
void HashTable::readCSVdebug(string fname){

    vector<vector<string>> parsedCSV = readCSV(fname);

    vector<vector<string>> output = takeLastMonthData(parsedCSV);

    for(int i = 0; i < output.size(); ++i){

        for(int j = 0; j < output[i].size(); ++j){

            cout<<output[i][j]<<", ";
        }
        cout<<endl;
    }
}
