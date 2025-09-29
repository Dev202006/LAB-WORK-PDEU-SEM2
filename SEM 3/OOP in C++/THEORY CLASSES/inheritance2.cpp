/*
Create a base class Person with data members: string name and int age and a member function to display the details. 
Now, create a derived class Student which inherits from Person and adds: int rollNumber and float marks.
 Write a program to input details of a student and display them using appropriate functions.
*/

#include<iostream>
using namespace std; 

class Person
{
    public: 
    string name; 
    int age; 

    Person()
    {
        name = "Unknown"; 
        age = 0; 
    }
    void virtual Display()
    {
        cout<<"The name of the person is: "<<name<<endl; 
        cout<<"The age of the person is: "<<age<<endl; 
    }
};
class Student: public Person
{
public: 
int rollno; 
float marks; 
Student(){
    rollno = 00; 
    marks = 00; 
}
void Display()
{
  cout<<"Roll no. of the student is: "<<rollno<<endl; 
  cout<<"The marks of the student are: "<<marks<<endl;   
}

void input(int rollno,float marks, int age, string name)
{
    this->rollno = rollno; 
    this->marks = marks; 
    this->name = name; 
    this->age = age; 
}

};

int main()
{
    // we did following things: 
    /*
    inheritance: the student class inherits person's methods and attributes
    polymorhpism / function overloading : the display function has different applications based on which class object we have created
    using dynamic allocations to bypass polymorphism and access the functions of parent class with same name or limit the application to a smaller number of functionality
    virtual function (overriding): in the base class... you're telling the compiler that you have to call this function for object of type base_class

    */
    Student s1; 
    cout<<"Displaying the default constructor creation...\n"; 
    s1.Display(); 
    s1.input(227,100.00,15,"Yugu"); 
    cout<<"Displaying Person class display function...\n";
    s1.Display(); //should only display name and age; 
    cout<<"Displaying Student class display function...\n";
    s1.Display(); 
    cout<<"working\n";
    Person *ptr = new Student(); //works - magic!
    ptr->Display(); //will display from person type if overriding is not done
    


}