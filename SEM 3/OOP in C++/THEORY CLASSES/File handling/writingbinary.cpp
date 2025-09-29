#include<iostream>
#include<fstream>

using namespace std; 

int main()
{
    string str = "My name is Dev";
    struct s {
        int i[5]; 
        char c; 
    };
    fstream fs("firstfile.bin", ios::binary|ios::out);
    struct s s1{{1,2,3,4,5},'a'};

    fs.write(( struct s*) &s1, sizeof(s1) );
    
}