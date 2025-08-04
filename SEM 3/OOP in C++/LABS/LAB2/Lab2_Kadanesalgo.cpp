//Largest contiguous Subarray using Kadane's Algorithm
//Time taken total = 15 minutes (5 minuts of code + 5 minutes of understanding + 5 minutes of extension to print the largest subarray)
//Time complexity: Order of n (wayyyy more efficient than the last one)
#include<iostream>
#include<vector>
using namespace std; 
int main(void)
{
    vector<int> v = {3, -2, 5, -1, 6, -3, 2, 7, -5, 2, -8, 4, 9, -10, 6}; 
    //initializes current sum and max sum as the first element
    int csum = v[0];
    int maxsum = v[0];
    vector <int> sub = {v[0]};
    int start = 0,end = 0, temp = 0; 

    for(int i =1;i<v.size();i++)
    {
        //if adding an element makes the sum increase then we will, if not, then not 
        if(v[i]<(v[i]+csum))
        {
            csum = csum + v[i];
        }
        else
        {
            //initialize at this point
            csum = v[i];
            temp = i; 
        }

        //updates max sum
        if (csum>maxsum)
        {
            maxsum = csum; 
            start = temp; 
            end = i; 
            
        }
    }
    cout<<"The maximum sum is: "<<maxsum; 
    cout<<endl<<"The maximum sub is: ";
    for(int i = start;i<=end;i++)
    {
        cout<<v[i]<<" ";
    }
}