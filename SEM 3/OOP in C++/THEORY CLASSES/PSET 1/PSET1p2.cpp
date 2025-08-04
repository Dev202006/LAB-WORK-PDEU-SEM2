//LCM using UDF
//time taken : 5 minutes

#include<iostream>
using namespace std;
int LCM(int x,int y);
int main(void)
{
    int x;
    int y;
    cout<<"Enter an integer: ";
    cin>>x;
    cout<<endl<<"Enter an integer: ";
    cin>>y;
    int lcm = LCM(x,y);
    cout<<endl<<"The LCM is: "<<lcm;
}
int LCM(int x, int y)
{
    int larger;
    if (x>=y)
        larger = x;
    else
        larger = y;
    while(1)
    {
        if (larger%x ==0 && larger%y ==0)
            return larger;
        else
            larger++;
    }
}
