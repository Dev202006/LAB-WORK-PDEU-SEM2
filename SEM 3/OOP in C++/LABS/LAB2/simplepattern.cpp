/*
*
* *
* * *
* * * *
*/
#include<iostream>
using namespace std; 
int main(void)
{
    int lim = 4; 
    for(int i=0;i<lim;i++)
    {
        for(int j = 0;j<=i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}