//WAP: create class base (attributes: d1 public ,d2 private ,d3 protected) 
//define derived (attribute d4 private) mode protected / private / public
//demonstrate the difference between modes of inheritance through derived class object 

#include<iostream>
using namespace std; 

class base{

    
    private: 
    int d2 = 2; 
    protected: 
    int d3 = 3; 
    public: 
    int d1 =1; 
    base()
    {
        cout<<"Base class Default constructor called"; 
    }
    ~base()
    {
        cout<<"Base class destructor called"; 
    }


}; 
class derived1: public base{
    //is public so protected can be accessed , public can be accessed, private can't be accessed
    int d4; 
    public: 
    derived1(int n ): d4(n){
    cout<<"The public attribute d1 in base class is: "<<d1; 
    cout<<"The protected attribute d3 is : "<<d3; 
    cout<<"The private member d2 cannot be accessed: "; 
    cout<<"The private member of this class (d4) can be accessed: "<<d4;

    }

    


};
class derived2: private base{
    //is public so protected can be accessed , public can be accessed, private can't be accessed
    int d4; 
    public: 
    derived2(int n ): d4(n){
    cout<<"The public attribute d1 in base class is: "<<d1; 
    cout<<"The protected attribute d3 is : "<<d3; 
    cout<<"The private member d2 cannot be accessed: "; 
    cout<<"The private member of this class (d4) can be accessed: "<<d4;

    }
