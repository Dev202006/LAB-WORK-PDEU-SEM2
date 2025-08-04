/*
*******
 *****
  ***
   *
  ***
 *****
*******

*/

//print hourglass patter using asterix.
//TIME TAKEN: 7 minutes
#include<iostream>

using namespace std;

int main()
{
    //loop one narrows:
    int limit;//can only be in odd numbers
    cout<<"Enter a limit of asterisk numbers(only odd digits):";
    cin>>limit;
    int acount = limit; //asterisk count: reduces by 2 every time you print
    int scount = 0;//space count increases by 1


    while(acount >=1)
    {
        for(int s=0;s<scount;s++)
            cout<<" ";
        for(int j = 0;j<acount;j++)
            cout<<"*";
        cout<<endl;
        acount = acount-2;
        scount = scount +1;
    }
    acount = acount +2;
    scount = scount -1;
    while(acount<=limit)
    {
        for(int s=0;s<scount;s++)
            cout<<" ";
        for(int j = 0;j<acount;j++)
            cout<<"*";
        cout<<endl;
        acount = acount+2;
        scount = scount-1;
    }
}

