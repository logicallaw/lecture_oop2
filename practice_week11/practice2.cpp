#include <string>
#include <iostream>

using namespace std;

class Date{
public:
    int day, month, year;
    Date() : year{ 2023 }, month{ 1 }, day{ 1 } {}
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
};

std::ostream& operator<<(std::ostream& out, const Date& d){
    out << d.day << "/" << d.month << "/" << d.year << endl;
    return out;
}

std::istream& operator>>(std::istream& in, Date& d){
    in >> d.day >> d.month >> d.year;
    return in;
}

int main(){
    Date d;
    Date d2;

    cout << d;
    cout << "Enter Date (in dd/mm/yyyy):";
    cin >> d2;
    cout << d2;
    return 0;
}