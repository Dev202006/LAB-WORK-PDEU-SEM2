
#include<iostream>
using namespace std; 

int main()
{
    try {
    int x,y;
    cout << "Enter a number: ";
    cin >> x;
    cout<<"Enter it's divisor: ";
    cin>>y;

    if (y == 0)
        throw 0;        // throw int
    if (x/y < 0)
        throw string("Negative result!"); // throw string
    cout << "Result is x/y: " << x/y<< endl;
}
catch (int e) {
    cout << "Caught exception: division by zero" << endl;
}
catch (string &e) {
    cout << "Caught exception: " << e << endl;
}
}