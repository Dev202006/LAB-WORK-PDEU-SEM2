//largest subarray programme (TYPE: BRUTEFORCE)
//first time we're going to use vectors
//Time Complexity: Cubic (n^3)
//lines : 47
//time taken to code: 25 minutes(concept + coding + debugging)
#include<iostream>
#include<vector>
using namespace std; 

int main(void)
{
    //defining the vector
    vector<int> v ={3, -2, 5, -1, 6, -3, 2, 7, -5, 2, -8, 4, 9, -10, 6}; 
    int n = v.size(); 
    //largest subarray initialization
    vector <int> bigsub = {v[0]};
    //initially is only the first element and sum is also same
    int bigsum = v[0];
    
    //there are n-1 possibilities for the size of the subarray
    for(int i =1;i<n;i++)
    {
        //every subarray starts at 0
        int size = i; 
        int start = 0; 
        int end = start+i; 
        //checks all subarray of size i until end of the vector is reached
        while(end<=n)
        {
            //current subarray
            vector<int> sub; 
            //current sum initialized to zero
            int sum=0; 
            //add elements between start to end ot the current subarray
            for(int x = start;x<end;x++)
            {
                sub.push_back(v[x]);
                sum = sum + v[x];
            }
            //condition to be characterized as the largest contiguous subarray
            if(sum>bigsum)
            {
                bigsub = sub; 
                bigsum = sum; 
            }
            //shifts by 1 index.
            start = start +1; 
            end = end +1; 
        }


    }
    //spits out result
    cout<<"The largest subarray: ";
    for(int i =0;i<bigsub.size();i++)
    {
        cout<<bigsub[i]<< " ";
    }
    cout<<"and the sum is: "<<bigsum;

}