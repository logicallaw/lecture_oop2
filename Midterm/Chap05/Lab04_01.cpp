#include <iostream>
using namespace std;
class Car{
private:
    string model = "null";
    string color = "null";
    int year = 0;
public:
    Car() {}
    Car(string model)
        : model{ model } {}
    Car(string model, string color)
        : Car{ model } { this->color = color; }
//    Car(string model, string color)
//        : Car{ model }, color{ color }{}
    Car(string model, string color, int year)
        : Car{ model, color } { this->year = year; }

    void printInfo() const;
};
void Car::printInfo() const {
    cout << "model: " << model << endl;
    cout << "color: " << color << endl;
    cout << "year: " << year << endl;

}
int main(void){
    Car* car1 = new Car();
    Car* car2 = new Car("MC20");
    Car* car3 = new Car("MC20", "green");
    Car* car4 = new Car("MC20", "red", 2001);

    car1->printInfo();
    (*car2).printInfo();
    car3->printInfo();
    (*car4).printInfo();

    delete car1;
    delete car2;
    delete car3;
    delete car4;
    return 0;
}