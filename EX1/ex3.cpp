#include <iostream>
#include <stdexcept>
using namespace std;

class DivideByZeroException : public runtime_error {
public:
    DivideByZeroException() : runtime_error("Division by zero") {}
};

double divide(int a, int b) {
    if (b == 0) {
        throw DivideByZeroException();
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        cout << divide(10, 0) << endl;
    } catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    }
    return 0;
}