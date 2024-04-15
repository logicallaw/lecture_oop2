#include <iostream>
using namespace std;
class Tmp{
public:
    Tmp(int day)
        : year { day / 365 } , day{ day % 365 } {}
    void display() {
        cout << "year: " << year << ", day: " << day << endl;
    }
    operator int() const{ //Tmp 클래스타입을 int타입으로 변환할 때 리턴값으로 year * 365 + day;를 리턴한다.
        return year * 365 + day;
    }

private:
    int year;
    int day;
};

int main(void){
    Tmp t{1000};
    t.display();

    Tmp t2 = 2000;
    t2.display();

    static_cast<Tmp>(2000).display();
    cout << static_cast<int>(t) << endl;
    return 0;
}