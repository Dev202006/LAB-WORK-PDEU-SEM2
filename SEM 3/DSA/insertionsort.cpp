//insertion sort


#include<iostream>

using namespace std; 

int main(void)
{
    int mylist[5] = {5,4,3,2,1}; 
    int n = sizeof(mylist);

    for(int i =0;i<n;i++)
    {
        int key = mylist[i];
        int j =i-1;
        
        while (j>=0 && mylist[j]>key)
        {
            mylist[j+1] = mylist[j];
            j--;
      }
            mylist[j+1] = key; 
    }
    for(int i=0;i<n;i++)
    {
        cout<<mylist[i]<<" ";
    }
}