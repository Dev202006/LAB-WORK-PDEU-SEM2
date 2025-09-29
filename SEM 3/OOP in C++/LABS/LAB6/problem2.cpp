#include<iostream>
using namespace std; 

class vehicle
{
protected: 
string color; 
public: 
vehicle(string color): color(color){}
void displaycolor()
{
    cout<<"The color is: "<<color<<endl; 
}
};

class car: public vehicle
{
    private: 
    string model; 
    int year; 
    public: 
    car(string color, string model,int year): vehicle(color){
        this->model =model; 
        this->year = year; 
    }
    car(): car("White","Unknown Model",2023)
    {

        model = "unknown"; 
        year = 0; 
    }
    void DisplayCarDetails()
    {
        displaycolor(); 
        cout<<this->model<<" is the model.\n"; 
        cout<<this->year <<" is the year.\n";

    }

};

int main()
{
    car idk; 
    car honda("Red","Amaze",2015); 
    idk.DisplayCarDetails(); 
    honda.DisplayCarDetails();
}
