#include<iostream>
using namespace std; 
int main(void)
{
    int x;
    int y; 
    cout<<"Enter first integer x: "; 
    cin>>x; 
    cout<<endl<<"Enter second integer y: ";
    cin>>y; 

    //swapping now

    x = x*y;
    y = x/y;
    x = x/y;
    cout<<"The first integer x now is: "<<x<<" and the second integer y now is: "<<y; 
}