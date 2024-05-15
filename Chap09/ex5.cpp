#include <iostream>
using namespace std;
class myClass{
public:
    myClass(const string& m) : data{ m }{
        cout << "constructor: " << data << endl;
    }
    myClass(const myClass& r) : data{ r.data + " (copy)" }{
        cout << "Copy constructor: " << data << endl;
    }
    string print() const {return data;}
    ~myClass() { cout << "destructor: " << endl; }
private:
    string data;
};

int main(){
    try{
        myClass my{"Data!"};
        throw my;
    }
    catch(const myClass& e){
        cout << "catch block: " << e.print() << endl;
    }
    return 0;

}