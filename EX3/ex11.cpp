#include <iostream>
using namespace std;
class Date{
public:
    int day, month, year;
    Date() : year{ 2023 }, month{ 1 }, day{ 1 } {};
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};
ostream& operator<<(ostream& out, const Date& d){
    cout << d.day << "/" << d.month << "/" << d.year;
    return out;
}
istream& operator>>(istream& in, Date& d){
    cin >> d.day >> d.month >> d.year;
    return in;
}

int main(void){
    Date d;
    Date d2;

    cout << d << endl;
    cout << "Enter Date (in dd/mm/yyyy):";
    cin >> d2;
    cout << d2;
    return 0;
}