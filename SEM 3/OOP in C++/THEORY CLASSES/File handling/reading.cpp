#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream file("file.txt");
    string s;

    //file >> s;        // Gives only one string 
    // cout << s;   // Gives only one line 
    while (!file.eof())
    {
        getline(file , s); 
        cout << s << endl ;
       
    }
    
    return 0;
}