#include <iostream>
#include <string>
using namespace std;
class myClass{
public:
    myClass(const string& m) : data{ m } {
        cout << "constructor: " << data << endl;
    }
    myClass(const myClass& r) : data{ r.data + " (copy)" } {
        cout << "Copy constructor: " << data << endl;
    }
    string print() const { return data; }
    ~myClass() { cout << "destructor: " << data << endl; }
private:
    string data;
};

int main(void){
    try{
        myClass my{ "Data!"};
        throw &my;
    }
    catch (myClass* e){
        cout << e->print() << endl;
    }
    return 0;
}