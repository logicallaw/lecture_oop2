#include <iostream>
#include <string>
using namespace std;
class PhoneNumber{
    friend ostream& operator<<(ostream& out, const PhoneNumber& number); //global function
    friend istream& operator>>(istream& input, PhoneNumber& number);
private:
    string areaCode;
    string exchange;
    string line;
};
//글로벌 함수 정의는 다음과 같이 일반 전역함수 정의하는 것처럼 하면 된다.
//이때, friend 키워드는 생략한다.
//글로벌 friend function의 목적은 클래스 private 멤버에 접근을 위해서이다.
ostream& operator<<(ostream& out, const PhoneNumber& number){
    out << "Area code: " << number.areaCode << endl;
    out << "Exchange: " << number.exchange << endl;
    out << "Line: " << number.line << endl;
    return out;
}
istream& operator>>(istream& input, PhoneNumber& number){
    input.ignore();
    input >> number.areaCode;
    input.ignore();
    input >> number.exchange;
    input.ignore();
    input >> number.line;
    return input;
}
int main(void){
    PhoneNumber phone;
    cout << "Enter phone number in the form (555) 555-5555: " << endl;
    cin >> phone;

    cout << endl;
    cout << phone << endl;
    return 0;
}