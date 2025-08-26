#include<iostream>
using namespace std;

class Complex //class definition
{
    public:
    int r;
    int i;
    Complex(int real, int imag) //Parameterized constructor
    {
        r = real;
        i = imag;
    }
    Complex() //Default constructor
    {
        r = 0;
        i = 0;
    }
    Complex operator+(Complex other) { //operator overload function
    return Complex(r + other.r,i+other.i); //directly returns the desired operator.
    }
    void display()
    {
        cout<<r<<" + i"<<i;//displays the complex number in common notation
    }
};
int main()
{

    Complex x;
    Complex a(1,2);
    Complex b(3,4);
    x = a + b;
    cout<<"We're adding ";
    a.display();
    cout<<" and ";
    b.display();
    cout<<"\nThe result is: ";
    x.display();

}
