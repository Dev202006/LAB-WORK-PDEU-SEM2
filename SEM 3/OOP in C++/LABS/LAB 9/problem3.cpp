#include <iostream>
#include<stdexcept>
using namespace std;

class DivideByZeroException:public runtime_error{

    public: 

    DivideByZeroException(const char *c): runtime_error(c){}

    

};
double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0.0)
        throw DivideByZeroException("Error: Division by zero is not allowed!");

    return numerator / denominator;
}



#include <iostream>
using namespace std;

int main()
{
    try {
        double result = divideNumbers(10.0, 2.0);
        cout << "Result: " << result << endl;
    }
    catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    }

    // Now the invalid case
    try {
        double result = divideNumbers(10.0, 0.0);
        cout << "Result: " << result << endl;
    }
    catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "An unexpected error occurred!" << endl;
    }

    return 0;
}
