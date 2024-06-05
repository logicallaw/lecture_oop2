#include <iostream>
using namespace std;
class myClass {
private:
    string data;
public:
    myClass(const string& m) : data{ m } {
        cout << "constructor: " << data << endl;
    }
    myClass(const myClass& r) : data{ r.data + " (copy)"} {
        cout << "Copy constructor: " << data << endl;
    }
    string print() const { return data; }
    ~myClass() { cout << "destructor: " << data << endl; }
};

int main(){
    try{
        myClass my{"Data!"};
        throw my;
    }
    catch(myClass e){
        cout << e.print() << endl;
    }
    return 0;
}