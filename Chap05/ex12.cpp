#include <iostream>
using namespace std;
class Car{
private:
    string model;
    string color;
public:
    Car(){}
    Car(string model)
        : model { model } {}
    Car(string model, string color)
        : color{ color }, Car{ model } {}
};