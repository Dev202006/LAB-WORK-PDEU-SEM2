#include<iostream>
#include<cstring>//to use strcpy
using namespace std;

class Student{
    private:
    char* name; // a dynamic pointer variable
    float marks;
    int roll;
    public:
    //default constructor
    Student(){
        name = new char[8]; //makes memory for 8 characters on the heap
        strcpy(name,"Unknown"); //because we donot want the memory to leak here
        marks = 0.0;
        roll = 0;
    }
    //parameterized constructor
    Student(const char *n, float m, int r)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        marks = m;
        roll = r;
    }
    //display function : get
    void display()
    {
        cout<<"The student named "<<name<<" has roll number "<<roll<<" and marks "<<marks<<endl;
    }
    ~Student()
    {
        delete[] name; 
    }


};
int main(void)
{
    Student s;
    Student s2("Rajesh",80.55, 5);
    s.display();
    s2.display();

}
