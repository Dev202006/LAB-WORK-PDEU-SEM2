//programme to demonstrate the difference between vectors and arrays

#include <iostream>
#include <vector>//need to include vector library to use vectors while arrays are a part of standard library
using namespace std;

int main() {
    // arrays are static means they have a fixed size and are declared at compile time
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array contents (fixed size): ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Trying to add another element to array is not possible
    // arr[5] = 6; This will cause a runtime error or undefined behavior

    // but vectors havea dynamic size
    vector<int> v = {1,2,3};
    cout << "Vector contents beforee:  ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    // You can add more elements dynamically unlike an array
    v.push_back(4);
    v.push_back(4);
    cout << "Vector contents (after push_back): ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    // Accessing elements is same
    cout << "Second element in array: " << arr[1] << endl;
    cout << "Second element in vector: " << v[1] << endl;

    // Arrays don't have methods but vectors have methods
    cout << "Size of vector: " << v.size() << "\n";
    cout << "Capacity of vector: " << v.capacity() << endl; // A vector always reserves more than it's size to avoid reallocating huge chunks of memory
    v.reserve(100);
    cout<<"Capacity of vector after reserving:"<<v.capacity()<<endl; //We increased reserve capacity

    // Array memory is continuous and known at compile time
    cout << "Address of arr[0]: " << &arr[0] << endl;
    cout << "Address of arr[1]: " << &arr[1] << endl;

    // Vectors are also continuous but managed at runtime often by reallocating memory as it goes
    cout << "Address of v[0]: " << &v[0] << endl;
    cout << "Address of v[1]: " << &v[1] << endl;

    return 0;
}
