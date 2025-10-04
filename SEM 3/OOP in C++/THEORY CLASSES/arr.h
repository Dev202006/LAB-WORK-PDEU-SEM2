#ifndef ARR_H
#define ARR_H

#include <iostream>
using namespace std;

template <typename T>
class arr {
public: 
    int size; 
    T *my_array;

    // Constructor
    arr(int size): size(size) {
        my_array = new T[size];
        T n; 
        for(int i = 0; i < size; i++) {
            cout << "\nEnter the element: ";
            cin >> n; 
            my_array[i] = n; 
        }
    }

    // Destructor
    ~arr() {
        delete[] my_array;
    }

    // Sorting algorithm (bubble sort)
    void sort() {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - i - 1; j++) {
                if(my_array[j] > my_array[j + 1]) {
                    T temp = my_array[j];
                    my_array[j] = my_array[j + 1];
                    my_array[j + 1] = temp;
                }
            }
        }

        cout << "\nSorted array: ";
        for(int k = 0; k < size; k++) {
            cout << my_array[k] << "\n";
        }
    }
};

#endif // ARR_H
