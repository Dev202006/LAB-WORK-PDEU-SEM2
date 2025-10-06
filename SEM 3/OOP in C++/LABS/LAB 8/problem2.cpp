#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;
int main()
{
    ifstream intput_file("test.txt" , ios :: in);
    if (!intput_file) { cerr << "Cannot open input\n"; return 1; }


    char ch;
    string mystring; 
    while (intput_file.get(ch)) {
        mystring = mystring + ch;  
    }
    intput_file.close();

    ofstream output_file("test.txt" , ios :: out);
    if (!output_file) { cerr << "Cannot open output\n"; return 1; }
    for(int i = 0; i<mystring.size();i++)
    {
        output_file.put(static_cast<char>(toupper(static_cast<unsigned char>(mystring[i]))));
    }
    

    
    
    output_file.close();

   
    cout << "File has been successfully converted to uppercase and saved to " << endl;

    return 0;
}