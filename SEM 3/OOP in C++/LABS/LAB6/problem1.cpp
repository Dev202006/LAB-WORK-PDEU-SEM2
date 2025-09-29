#include<iostream>
using namespace std; 

class person
{
    private: 
        string name; 
        int age; 
    public: 
        person(string n, int a)
        {
            name = n; 
            age = a; 
        }
        void virtual display(){
            cout<<"Person name is: "<<name<<endl; 
            cout<<"Person age is: "<<age<<endl;

        }
}; 
class student: public person{
    private: 
    string name; 
    int age; 
    string studentid; 
    string major; 
    public: 
    student(string n, int a, string sid,string m): person(n,a){
        studentid = sid; 
        major = m; 
    }
    void display()
    {
        //displayperson(); 
        cout<<"Student Id: "<<studentid<<endl; 
        cout<<"Major: "<<major<<endl; 
    }
};

int main(void)
{
    cout<<"Using basic: \n";
    student s1("Vismay Shah",19,"24BCP230","Computer Science");
    //s1.displaystudent(); 
    
    cout<<"Using dynamic one: \n";
    person *ptr = &s1; 
    ptr->display();
    

}