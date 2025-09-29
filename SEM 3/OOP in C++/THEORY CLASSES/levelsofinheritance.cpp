#include<iostream>
using namespace std; 

class base
{
    public: 
    int baseno; 
    base(int baseno):baseno(baseno){}
    void virtual display(){cout<<"Base number is: "<<baseno<<endl;}
    ~base()
    {
        cout<<"base destroyed!";
    }
    
};


//single inheritance

class single : public base 
{
    public: 
    int singleno;
    single(int singleno,int baseno):base(baseno),singleno(singleno){}
    void display() override {display(); cout<<"Singleno is :"<<singleno<<endl;}
    ~single()
    {
    cout<<"Single child destroyed!\n";
    }
};

//multilevel inheritance
class baselevel
{
public: 
string levelname; 
baselevel(string levelname):levelname(levelname){cout<<"Zeroth level created!\n";}
void displaylevel(){cout<<"You are at the zeroth level. The level name is: "<<levelname<<endl;}
~baselevel()
{
    cout<<"Base level destroyed!";
}

};
class level1:public baselevel
{
public: 
int height; 
level1(string levelname,int height):baselevel(levelname),height(height){cout<<"Zeroth level created!\n";}
void displaylevel(){cout<<"You are at the first level. The level name is: "<<levelname<<endl<<"The level height is: "<<height<<endl;}
~level1()
{
    cout<<"Level1 destroyed!";
}

};
class level2: public level1
{
    public:
    int height_above_l1;
    level2(string levelname, int height, int height_above_l1): level1(levelname,height),height_above_l1(height_above_l1){}
    void displaylevel(){cout<<"You are at the first level. The level name is: "<<levelname<<endl<<"The level height is: "<<height<<endl<<"The level height above firstl evel is: "<<height_above_l1<<endl;}
    ~level2()
    {
        cout<<"Level 2 is distroyed!";
    }
};


void main()
{
    cout<<"projected output: base constructor\n";
    base b1(15); 
    cout<<"bprojected output: base, single constructor\n";
    single(15,25);


}