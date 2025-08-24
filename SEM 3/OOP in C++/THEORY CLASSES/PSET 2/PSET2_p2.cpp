#include<iostream>
using namespace std;
int seat_num = 0;
class Passenger{
    public:
    string Pas_name;
    string destination;
    int seat;

    Passenger(string name, string desti){
        seat_num++;
        seat = seat_num;
        Pas_name = name;
        destination = desti;
    }
    void display(){
        cout << "Passenger name : " << Pas_name << endl;
        cout << "Passenger Destination: " << destination << endl;
        cout << "Passenger Seat Number : " << seat << endl;
    }
    ~Passenger(){
        seat_num--;
        cout << "Seat number : "<< seat << " is removed !" << endl;
        cout<<"Seat holder name: "<<Pas_name; 
    }
};
int main()
{
    while (1)
    {string name , desti;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the Destination of passengers: ";
    cin >> desti;

    Passenger pas1(name , desti); 
    pas1.display();
    int choice;
    cout << "Do you want to cancel this seat : ";
    cin >> choice;
    if (choice == 1)
    {
        break;
    }
    cout<<"You are now checking out!";
    }
    
    
    return 0;
}