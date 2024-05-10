#include <iostream>
using namespace std;
class Car{
public:
    void start() { cout << "Start" << endl; }
    void end() { cout << "End" << endl; }
};

class Bike:public Car{
public:
    void start() { cout << "Inherited Start" << endl; }
    void end() { cout << "Inherited End" << endl; }
};

int main(void){
    Car* c = new Car;
    c->start(); //Start
    c->end(); //End
    c = new Bike;
    c->start(); //Start
    c->end(); //End
    return 0;
}