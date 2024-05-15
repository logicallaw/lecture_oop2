#include <iostream>
using namespace std;
class DivideByZeroException{
public:
    DivideByZeroException(const string& m) : data{ m } {}
    string print() const { return data; }
private:
    string data;
};
double quotient(int numerator, int denominator){
    if (denominator == 0)
        throw DivideByZeroException("Division by 0");
    return static_cast<double>(numerator) / denominator;
}

int main(void){
    int number1{ 5 };
    int number2{ 0 };
    try{
        cout << quotient(number1, number2);
    }
    catch(const DivideByZeroException& e){
        cout << e.print() << endl;
    }
    return 0;
}
