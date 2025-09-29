#include<iostream>
using namespace std; 

class animal{

    public: 
    void virtual makesound() final
    {
        cout<<"Growllllll"<<endl; 

    }
    void virtual eat()
    {
        cout<<"Animal has eaten. he loves the food!"<<endl; 
    }

};

class dog: public animal{

    public: 
    /*
    compile time error: 
    cannot override 'final' function "animal::makesound" (declared at line 7)
    void virtual makesound() override
    {
        cout<<"barkkkkk"<<endl; 
    }
    */
    void eat() override
    {
        cout<<"The Dog has eaten. he actually just plays with food! "<<endl ; //doesn't cause any error since it's not a final function
    }

};

int main()
{
    dog waffle; 
    waffle.eat();
    animal *p = &waffle; 
    p->eat(); //does the same thing since it's a vitual function

    animal munchkin; 
    munchkin.eat(); //does a different thing. 
}