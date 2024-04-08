#include <iostream>
#include <array>
using namespace std;

class Date{
private:
    friend ostream& operator<<(ostream&, const Date&);
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const array<unsigned int, 13> days;
    void helpIncrement();
public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++(); //prefix - return Lvalue
    Date operator++(int); //postfix - return Rvalue
    Date& operator+=(unsigned int); //return Lvalue
    static bool leapYear(int);
    bool endOfMonth(int) const;
};

const array<unsigned int, 13> Date::days{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int month, int day, int year){
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd , int yy) {
    if (mm >= 1 && mm <= 12){
        month = mm;
    }
    else{
        throw invalid_argument("Month mush be 1-12");
    }

    if (yy >= 1900 && yy <= 2100){
        year = yy;
    }
    else{
        throw invalid_argument("Year mush be 1900-2100");
    }

    if ((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29)){
        day = dd;
    }
    else{
        throw invalid_argument(
            "Day is out of range for current month and year");
    }
}

Date& Date::operator++() {
    helpIncrement();
    return *this;
}
Date Date::operator++(int) {
    Date temp{*this};
    helpIncrement();
    return temp;
}

Date& Date::operator+=(unsigned int additionalDays){
    for (int i{ 0 }; i < additionalDays; i++){
        helpIncrement();
    }
    return *this;
}

bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
}

bool Date::endOfMonth(int testDay) const {
    if (month == 2 && leapYear(year)){
        return testDay == 29;
    } else {
        return testDay == days[month];
    }
}

void Date::helpIncrement() {
    if (!endOfMonth(day)){
        ++day;
    }
    else {
        if (month < 12){
            ++month;
            day = 1;
        }
        else {
            ++year;
            month = 1;
            day = 1;
        }
    }
}

ostream& operator<<(ostream& output, const Date& d){
    static string monthName[13]{
        "", "January", "February", "March", "April", "May", "June", "July", "Augest",
        "September", "October", "November", "December"};
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;
    return output;
}

int main(void){
    Date d1{12, 27, 2010};
    Date d2;
    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\n\nd1 += 7 is " << (d1+=7);

    d2.setDate(2, 28, 2008);
    cout << "\n\n d2 is " << d2;
    cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3{7, 13, 2010};

    cout << "\n\nTesting the prefix increment operator:\n"
        << "\t d3 is " << d3 << endl;
    cout << "++d3 is " << (++d3) << endl;
    cout << "\td3 is " << d3;

    return 0;
}