#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream file("file.txt");
    string s; 
    int count_the = 0; 
    int count_a = 0; 
    int count_an = 0; 
    while(!file.eof())
    {
        file>>s; 
        if (s== "the")
            count_the ++; 
        else if (s=="a")
            count_a ++; 
        else if (s =="an")
            count_an ++;     
        
    }
    cout<<"The number of times the repeats is: "<<count_the<<endl; 
    cout<<"The number of times a is repeated is: "<<count_a<<endl; 
    cout<<"The number of times an is repeated is: "<<count_an<<endl; 

    
    return 0;
}