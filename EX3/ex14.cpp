#include <iostream>
using namespace std;
class Engine{
public:
    Engine(int nc){
        cylinder = nc;
    }
    void start(){
        cout << getCylinder() << " cylinder engine started" << endl;
    }
    int getCylinder() const{ return cylinder; }
private:
    int cylinder;
};

class Car: private Engine{
public:
    Car(int nc = 4) : Engine(nc) {}
    //start()
    void start(){
        cout << "car with " << getCylinder() << "engine started" << endl;
        Engine::start();
    }
};

int main(void){
    Car c(8);
    c.start();
    return 0;
}