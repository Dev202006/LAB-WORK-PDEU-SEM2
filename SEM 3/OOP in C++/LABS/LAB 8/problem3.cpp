#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    string fileName = "problem3test.txt";


    ifstream inputfile(fileName);
    if (!inputfile) {
        cerr << "Error: Could not open file " << fileName << " for reading." << endl;
        return 1;
    }

    
    set<string> uniqueLines;
    string line;

    while (getline(inputfile, line)) {
        uniqueLines.insert(line);
    }
    inputfile.close(); // Close input after reading

    ofstream outputfile(fileName);
    if (!outputfile) {
        cerr << "Error: Could not open file " << fileName << " for writing." << endl;
        return 1;
    }

    for (set<string>::iterator i = uniqueLines.begin(); i != uniqueLines.end(); i++) {
        outputfile << *i << "\n"; 
    }

    outputfile.close();

    cout << "Duplicate lines removed. File updated: " << fileName << endl;

    return 0;
}
