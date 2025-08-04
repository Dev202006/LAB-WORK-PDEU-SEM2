//Greatest common divisor (GCD)
//time taken: 15 minutes
//revelation: scoping error will occur if you define variables in a block (if else or loops) then it can't be accessed somewhere else.

#include<iostream>
using namespace std;

int main(void)
{
    int x;
    int y;
    int smallest;
    int gcd;
    //integer input
    cout<<"Enter an integer: "<<endl;
    cin>>x;
    cout<<"Enter an integer: ";
    cin>>y;

    // checking all the number lesser than the smallest number;
    if (x>=y)
    {
        int smallest = x;
    }
    else
    {
        smallest = y;
    }
    for(int i=smallest;i>=0;i--)
    {
      if (x%i ==0 && y%i==0)
      {
         gcd = i;
         break;
      }

    }


    cout<<endl<<"The greatest common divisor is: "<<gcd;






}
