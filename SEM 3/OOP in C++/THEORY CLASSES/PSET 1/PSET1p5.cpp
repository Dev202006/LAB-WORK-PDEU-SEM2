//Print diamond shape 
/*
123*
12***
1*****
*******0
 *****
  ***
   *
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
#formula for spaces = highest number of stars//2 
#start with stars = 1;spaces = starlim//2
#until spaces = 0
#then increase stars to starlim, and spaces to starlim//2
*/
//Time taken: 9 minutes 30 seconds

#include<iostream>
using namespace std; 

int main(void)
{
    int lim;
    cout<<"Enter the number of lines you want: "; 
    cin>>lim; 
    int spaces = lim/2;
    int stars = 1; 
    cout<<endl;
    while (spaces>=0)
    {
        for(int i=0;i<=spaces;i++)
            cout<<" "; 
        for(int j =0;j<stars;j++)
            cout<<"*";
        cout<<endl; 
        stars = stars +2; 
        spaces = spaces -1; 
    } 
    while (spaces<=lim/2)
    {
        for(int i=0;i<=spaces;i++)
            cout<<" "; 
        for(int j =0;j<stars;j++)
            cout<<"*";
        cout<<endl; 
        stars = stars -2; 
        spaces = spaces +1; 
    }


}