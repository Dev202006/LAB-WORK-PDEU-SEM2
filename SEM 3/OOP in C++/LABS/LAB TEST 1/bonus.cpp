#include<iostream>

using namespace std;
class roman;
class number{

    int i;
    public:
    number()
    {
        i = 0;
    };
    number(int n):i(n){}
    int get()
    {
        return i;
    }
    friend void convert(number N, roman &R);


};
class roman{
    //works only till 100
string r;
    public:
    roman()
    {
        r = "0";
    };
    roman(string l):r(l){}
    string get()
    {
        return r;
    }
    friend void convert(number N, roman &R);
};
void convert(number N, roman &R)
{
    //finds the number of fifties, tens, fives and ones and modifies the string attribute r of roman object R based on the common logic of natural to roman number conversion
    int n = N.i;
    string r = R.r;
        int tens = (n%50)/10;
        int fifties = n/50;
        int fives = (n%10)/5;
        int ones = (n%5);
        string newr;
    if (fifties)
    {
        if (tens == 4)
        {
            newr = "XC";
        }
        else
        {
            newr = "L";
            for(int x = 0; x<tens;x++)
            {
                newr = newr+"X";
            }
            if(fives)
            {
                if(ones==4)
                {
                    newr = newr+"IX";
                }
                else
                {
                    newr = newr + "V";
                    for(int x =0;x<ones;x++)
                    {
                        newr = newr+"I";
                    }
                }
            }
            else
            {
                if(ones ==4)
                {
                    newr = newr+"IV";
                }
                else
                {
                    for(int x =0;x<ones;x++)
                    {
                        newr = newr+"I";
                    }
                }

            }

        }

    }
    else
    {
        if (tens == 4)
        {
            newr = "XL";
        }
        else
        {
            for(int x = 0; x<tens;x++)
            {
                newr = newr+"X";
            }
            if(fives)
            {
                if(ones ==4)
                {
                    newr = newr+"IX";
                }
                else
                {
                    newr = newr + "V";
                    for(int x =0;x<ones;x++)
                    {
                        newr = newr+"I";
                    }
                }
            }
            else
            {
                if(ones ==4)
                {
                    newr = newr+"IV";
                }
                else
                {
                    for(int x =0;x<ones;x++)
                    {
                        newr = newr+"I";
                    }
                }

            }

        }

    }
    R.r = newr;

    }








int main(void)
{
    number x(25);
    cout<<"Initially the integer is: "<<x.get();
    roman r1("LXVI");
    cout<<"\nInitially the roman literal is: "<<r1.get();
    cout<<"\nThe roman number is: "<<r1.get();
    convert(x,r1);
    cout<<"\n\nThe roman number is now converted to based on the integer: "<<r1.get();
    number y(78);
    cout<<"\n\nThe integer is now: "<<y.get();
    convert(y,r1);
    cout<<"\nThe roman number is now: "<<r1.get();




}
