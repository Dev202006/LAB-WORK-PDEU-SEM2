#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;
int main()
{
    ifstream intput_file("test.txt" , ios :: in);
    ofstream output_file("test.txt" , ios :: out);

    char ch;
    while (intput_file.get(ch)) {
        
        output_file.put(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
    }

    
    intput_file.close();
    output_file.close();

   
    cout << "File has been successfully converted to uppercase and saved to " << endl;

    return 0;
}