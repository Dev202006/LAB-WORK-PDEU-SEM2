//WAP to create a class student with 3 attributes: name, rol no., branch
//define a constructor to give initial values to the object and hence no garbage


#include<iostream>
using namespace std;
class student
{
    int roll;
    string name;
    string branch;
public:
    student()
    {
        roll = 0;
        name = "initialname";
        branch = "initialbranch";
    }
    student(int r, string n, string b)
    {
        roll = r;
        name = n;
        branch = b;
    }
};

int main(void)
{
    student initial;
    student yug(1, "Yug shah", "CSE");
}
