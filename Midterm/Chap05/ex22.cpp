#include <iostream>
using namespace std;
class Car{
private:
    int a;
public:
    virtual void aa(){ cout << "hi" << endl;}
    void bb(){ cout << "dkd" << endl;}
};
class Brand:public Car{
private:
    int a;
public:
    void aa(){ cout << "bye" << endl; }
    void bb() { cout << "bye bb" << endl;}

};

int main(void){
    Brand b1;
    Car* pc;
    pc = &b1;
    pc->aa();
    pc->bb();
}