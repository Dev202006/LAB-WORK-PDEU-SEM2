/*
Write a C++ program to create a class called Triangle that has private member variables for the lengths of its three sides.
Implement member functions to determine if the triangle is equilateral, isosceles, or scalene.*/

#include<iostream>
using namespace std;

class Triangle{
private:
    int s1;
    int s2;
    int s3;
public:
    //constructors
    Triangle()
    {
        s1 =0; 
        s2=0;
        s3=0; 
    }
    Triangle(int a): s1(a),s2(a),s3(a){}
    
    Triangle(int a1,int a2,int a3)
    {
        cout<<"Parameterized constructor 2";
        s1 = a1;
        s2 = a2;
        s3 = a3;
    }
    //functions for the 3
    void Triangletype()
    {
        if(s1==s2 && s2 ==s3)
            cout<<"\nThe Triangle is equilateral";
        else if(s1 == s2 || s2 == s3 || s1 == s3)
            cout<<"\nThe Triangle is isosceles";
        else
            cout<<"\nThe triangle is scalene";
        }


};
int main()
{
    Triangle t1,t2(2),t3(3),t4(1,2,2),t5(1,2,3);
    t1.Triangletype();
    t4.Triangletype();
    t5.Triangletype();
}
