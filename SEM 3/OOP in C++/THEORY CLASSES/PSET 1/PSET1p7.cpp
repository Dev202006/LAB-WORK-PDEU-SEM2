//FACTORIAL USING RECURSION
//1*2*3*...*n

#include<iostream>

using namespace std;

int fact(int x);
int main(void)
{
    int x;
    cout<<"Enter a natural number: ";
    cin>>x;
    int f;
    f = fact(x);
    cout<<endl<<"The factorial of "<<x<<" is "<<f;

}
int fact(int x)
{
    if (x==1)
        return 1;
    else
        return x*fact(x-1);
}
