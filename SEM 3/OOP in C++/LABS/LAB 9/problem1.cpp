#include <iostream>
using namespace std;

template<typename T> T findMax(T x, T y, T z)
{
    try{
    
    if (x==y && x==z)
        throw 0;       
    else if ((x>=y) && (x>=z))
    {
        cout<<"\nThe maximum number is: "<<x; 
        return x; 
    }
    else if (y>=x && y>=z)
    {
    cout<<"\nThe maximum number is: "<<y; 
        return y;
    }
    
    else
    {
         cout<<"\nThe maximum number is: "<<z; 
        return z; 
    }
        
    }
    catch (int e)
    {
        if (e ==0)
            cout<<"\nEquality Error: All data members are equal";
    }
}

int main() {
    
    findMax(1,2,3);
    findMax(3.14,2.71,5.0);
    findMax('X','A','Z');
    findMax(1,1,1);
    return 0;
}