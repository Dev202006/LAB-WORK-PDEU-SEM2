//to remove spaces from a string

#include<iostream>
using namespace std;

int main(void)
{
    char sentence[100];
    char newsentence[100] = "";
    cout<<"Enter a string: ";
    cin>>sentence;
    int counter = 0;
    int i = 0;
    while(sentence[i]!=\0)
    {
        if (sentence[i]!=' ')
            newsentence[counter]=sentence[i];
            counter = counter +1;

    }
    cout<<endl<<"New sentence: "<<newsentence;

}
