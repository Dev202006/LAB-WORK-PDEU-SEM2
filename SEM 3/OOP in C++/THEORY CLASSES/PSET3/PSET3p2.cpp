
/*
Write a C++ program to implement a class called Date that has private member variables for day, month, and year. 
Include member functions to set and get these variables, as well as to validate if the date is valid.*/

#include<iostream>
using namespace std; 

class Date{
    private: 
    int d; 
    int m; 
    int y; 
    public: 
    Date(){};
    Date(int D, int M, int Y)
    {
        d = D; 
        m = M; 
        y = Y; 
    }
    void set(int D, int M, int Y)
    {
        d = D; 
        m = M; 
        y = Y; 
    }
    void get()
    {
        cout<<"\nThe date stored is: "<<d<<"/"<<m<<"/"<<y; 
    }
    string valid()
    {
        //general condition
        if(d > 0 && d <= 31 && m > 0 && m <= 12 && y > 0 && y <= 3000)
        {
            //for handling months with 31 days
            if((m<8 && m%2 ==0) || (m>=8 && m%2 ==1) && d==31)
            {
                return "false";  
            }
            else
                return "true"; 
            //for handling leap years and februaries BECAUSE THEY ARE SO SPECIAL
            if(m ==2)
            {
                if(y%4 ==0)
                    if (d>29)
                        return "false";
                    else
                        return "true"; 
                else
                {
                    if(d>28)
                        return "false";
                    else
                        return "true"; 
                }

            }


            
        }
        else
            return "false"; 
    }
};
int main()
{
    Date d1; 
    Date d2(1,12,2025); 
    d1.set(29,2,2025); 
    cout<<"DATE 1: ";
    d1.get(); 
    cout<<"DATE 2: "; 
    d2.get(); 
    string result = d2.valid(); 
    cout<<endl<<"Is d2 valid: "<<result; 
    string result2 = d1.valid(); 
    cout<<endl<<"Is d1 valid: "<<result2; 
    Date today(17,9,25);
    today.get(); 
    
}
