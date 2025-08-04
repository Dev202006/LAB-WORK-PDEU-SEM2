//IMPLIMENTING BUBBLE SORT USING C++
//time complexity: (n-1)n/2 i.e. Order(n^2)
//best case: O(n); worst case: O(n^2); average: n(n-1)/4 i.e. O(n^2)
//space complexity: 

#include<iostream>

using namespace std; 

int main(void)
{
    int mylist[10] = {5,6,1,2,-1,0,-100,50,7,3};
    int n = 10;
    //printing unsorted array: 
    cout<<"Unsorted array: "; 
    for(int i =0;i<n;i++)
        cout<<mylist[i]<<" ";
    cout<<endl; 
    for (int i =0;i<n;i++)
    {
        int flag = 1; 
        for(int j =0;j<n-1-i;j++)
        {
    
            if(mylist[j]>mylist[j+1])
            {
                int temp = mylist[j];
                mylist[j]=mylist[j+1];
                mylist[j+1] = temp; 
                flag = 0; 
            }
        }
        cout<<"code ran "<<i+1<<" times \n";
        if (flag)
            break;
    }
    //printing sorted array: 
    cout<<"Sorted Array array: "; 
    for(int i =0;i<n;i++)
        cout<<mylist[i]<<" ";
    cout<<endl;
    
}
