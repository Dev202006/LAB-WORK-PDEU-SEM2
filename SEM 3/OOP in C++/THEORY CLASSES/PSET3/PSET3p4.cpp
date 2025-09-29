#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;

public:
    // Parameterized Constructor
    Person(const char* inputName) {
        name = new char[strlen(inputName) + 1]; // +1 for null terminator
        strcpy(name, inputName);
        cout << "Constructor: Created person with name = " << name << endl;
    }

    // Deep Copy Constructor
    Person(const Person &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "Copy Constructor (Deep Copy): Copied person with name = " << name << endl;
    }

    // Destructor
    ~Person() {
        cout << "Destructor: Deleting person with name = " << name << endl;
        delete[] name;
    
    }

    // Function to update name
    void updateName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Function to display name
    void display() const {
        cout << "Person Name: " << name << endl;
    }
};

int main() {
    cout << "Creating person1...\n";
    Person person1("Alice");

    cout << "\nCreating person2 as a copy of person1...\n";
    Person person2 = person1; // also: Person person2(person1); // Triggers deep copy constructor because we only created that. 

    cout << "\nChanging name of person2 to Bob...\n";
    person2.updateName("Bob");

    cout << "\nDisplaying both persons:\n";
    person1.display();  // Should still be Alice
    person2.display();  // Should be Bob

    cout << "\nExiting main...\n";
    return 0;
}
