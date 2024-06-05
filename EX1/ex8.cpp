#include <iostream>
#include <stdexcept>
using namespace std;
class DivideByZeroException : public runtime_error{
public:
    DivideByZeroException() : runtime_error("Division by 0") {}
private:
    string data;
};

double quotient(int numerator, int denominator){
    if(denominator == 0){
        throw DivideByZeroException();
    }
    return static_cast<double>(numerator) / denominator;
}

int main(void){
    int number1 = 5;
    int number2 = 0;
    try{
        cout << quotient(number1, number2);
    }
    catch(const DivideByZeroException& e){
        cout << e.what()     << endl;
    }
    return 0;
}