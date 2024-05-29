#include <iostream>
#include <iomanip>
using namespace std;
class Tmp{
public:
    Tmp() {
        cout << "constructor" << endl;
    }
    ~Tmp(){
        cout << "destructor" << endl;
    }
};
int main(void){
    shared_ptr<Tmp> p1{ new Tmp() };
    weak_ptr<Tmp> p2{ p1 };
    cout << p2.lock() << endl;

}