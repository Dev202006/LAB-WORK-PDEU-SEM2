#include <iostream>
using namespace std;

template <typename T>
class my_arr {
public: 
    int size; 
    T *my_array;

    // Constructor
    my_arr(int size): size(size) {
        my_array = new T[size];
        T n; 
        for(int i = 0; i < size; i++) {
            cout << "\nEnter the element: ";
            cin >> n; 
            my_array[i] = n; 
        }
    }
    void set_element(int index, const T &value)
    {
        my_array[index] = value; 
        cout<<"The value has been updated to: "<<my_array[index]<<endl; 
    }
    
    void get_element(int index)
    {
        try{
            if (index>=size)
            {
                throw 1;
            }
            cout<<"The element at the position "<<index<<" is "<<my_array[index]<<endl;
        }
        catch(int e)
        {
            if (e ==1)
                cout<<"Index out of bounds!";

        }
        
    }

    // Destructor
    ~my_arr() {
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


int main()
{
    my_arr<int> intarray(3);
    my_arr<char> chararray(3);
    chararray.set_element(2,'b');
    chararray.get_element(2);
    intarray.get_element(3);
}
