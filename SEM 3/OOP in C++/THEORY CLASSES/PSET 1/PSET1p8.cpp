//check equality without arithmetic or conditional operator

/* logic is that bitwise XOR (^) gives zero for every digit when both digits are same. hence if the numbers are equal. bitwise xor will be zero only*/

#include<iostream>
using namespace std; 

int main(void)
{
    int i ;
    int j; 
    cout<<"Enter an integer: ";
    cin>>i; 
    cout<<endl<<"Enter another integer: ";
    cin>>j; 

    int verdict = i^j; 
    if(verdict)
        cout<<endl<<"Then numbers are not equal"; 
    else
        cout<<endl<<"The numbers are equal";
}
