/*
Pattern as follows: 
1
A B
2 3 4
C D E F
.
.
limit
*/

#include<iostream>
using namespace std; 
int main(void)
{
    //user defined number of rows
    int lim; 
    cout<<"Enter number of rows: ";
    cin>>lim; 
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //introducing counters which will remember where we left off
    int calpha = 0; 
    int cnum = 1; 
    //loops

    for(int i=0;i<lim;i++)
    {
        //if odd numbered iteration... i = 0,2,4,...
        if(i%2!=0)
        {
            for(int j =0;j<=i;j++)
            {
                cout<<cnum<<" ";
                cnum= cnum +1 ; 
            }
            cout<<endl;
        }
        //if even numbered iteration... i = 1,3,5,...
        if(i%2==0)
        {
            for(int j =0;j<=i;j++)
            {
                cout<<alpha[calpha]<<" ";
                calpha= calpha +1 ; 
            }
            cout<<endl; 
        }
    }


}