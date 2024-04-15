
#include <iostream>
using namespace std;
class Car{
private:
    string* model;
    string* color;
public:
    Car()
        : model{ new string { "GV80" } }, color{ new string{"green"} } {
        cout << "Car constructor" << endl;
    }
    virtual ~Car() {
        delete model;
        delete color;
        cout << "메모리 해제: model, color" << endl;
    }

    string getModel() const { return *model; }
    string getColor() const { return *color; }
};

class SubTmp : public Car{
private:
    int* year;
public:
    SubTmp()
        : year{ new int{2001} }{
        cout << "SubTmp constructor" << endl;
    }
    virtual ~SubTmp() {
        delete year;
        cout << "메모리 해제: year" << endl;
    }

    int getYear() const { return *year; }
};

int main(void){
    SubTmp st;
    cout << st.getModel() << endl;
    cout << st.getColor() << endl;
    cout << st.getYear() << endl;
    return 0;
}