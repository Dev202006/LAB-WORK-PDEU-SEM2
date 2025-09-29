#include<iostream>
#include<vector>
using namespace std; 

class SmartDevice
{
    protected: 
    string deviceid; 
    public: 
    SmartDevice(string deviceid){this->deviceid = deviceid;}
    virtual void displayStatus() = 0; 
    virtual void connect() = 0; 
    virtual ~SmartDevice(){cout<<"Smart Device destructor called\n";}
};

class SmartLight: public SmartDevice
{
   bool isOn; 
   string *color_mode;  
   public: 
   SmartLight(string deviceid,bool isOn,string color_mode): SmartDevice(deviceid), isOn(isOn){

    this->color_mode = new string(color_mode); 

   }
   virtual void displayStatus() override
   {
    if (isOn)
    {
        cout<<"Light is on and the color is: "<<*color_mode; 

    }
    else
    cout<<"Light is off";
   }   void connect() override
{
    cout<<"The light is connected!";


}
   ~SmartLight()
   {
    color_mode = nullptr; 
    cout<<"SmartLight Destructor Called";
   }
};

class SmartSpeaker: public SmartDevice
{
int volume ; 
string current_song;
public: 
SmartSpeaker(string deviceid,int volume,string current_song): SmartDevice(deviceid), volume(volume),current_song(current_song){}
void connect() override
{
    cout<<"The speaker is connected!";
}
void displayStatus() override
{
    cout<<"Volume: "<<volume;
    cout<<endl<<"Current Song: "<<current_song; 
    cout<<endl<<"Device id: "<<deviceid; 
}
~SmartSpeaker(){}


};

int main()
{
SmartLight *l1 = new SmartLight("01023",true,"Blue");
SmartSpeaker *s1 = new SmartSpeaker("98901",67,"Khamoshiya-Arijit Singh");

vector <SmartDevice*> v1  = {l1,s1}; 
for(int i = 0; i<v1.size();i++)
{
    v1[i]->connect();
    v1[i]->displayStatus();

}
for(int i = 0; i<v1.size();i++)
{
    delete v1[i]; 

}
}

