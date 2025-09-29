#include<iostream>
#include<vector>
using namespace std; 

class shape
{
    public: 
    void virtual displayInfo() const
    {
        cout<<"This is a shape \n";
    }
    virtual double calculateArea() const = 0; 
} ;  

class circle: public shape
{
double radius; 
public: 
circle(double radius):radius(radius){}

void virtual displayInfo() const override
{
    cout<<"This circle is of radius: "<<radius<<endl; 
}
double calculateArea() const override
{
double area = radius*radius*(22/7);
return area; 
}

};

class rectangle: public shape
{

    double length; 
    double width; 
public: 
rectangle(double l,double w):length(l),width(w){}

void virtual displayInfo() const override
{
    cout<<"This rectangle has length"<<length<<" and width: "<<width<<endl; 
}
double calculateArea() const override
{
double area = length*width; 
return area; 
}
};

int main()
{
    circle *c1 = new circle(2.0);
    rectangle *r1 = new rectangle(2.0,4.0);

    vector <shape*> v1 = {c1,r1}; 

    for(int i = 0; i< v1.size();i++)
    {
        v1[i]->displayInfo();
    }
}