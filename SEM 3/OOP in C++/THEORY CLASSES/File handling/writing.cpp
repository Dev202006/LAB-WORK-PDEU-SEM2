#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file("file.txt", ios::app);

    file << "This is the added line";
    return 0;
}