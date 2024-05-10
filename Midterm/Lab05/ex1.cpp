#include <iostream>
using namespace std;

class Tmp{
private:
    int a  = 7;
public:
    Tmp() = default;
    int print() const{ return a; }
};

int main(void){
    Tmp t1;
    cout << "1 | " << t1.print() << endl;

    Tmp* pt1 = &t1;
    cout << "2 | " << (pt1->print()) << endl;

    cout << "3 | " << (*pt1).print() << endl;
    return 0;
}

