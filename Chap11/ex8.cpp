#include <iostream>
#include <fstream>
using namespace std;
class Tmp{
public:
    Tmp(){}
    Tmp(int a, string b, double c)
    :a{ a }, b { b }, c { c }{
        cout << "constructor!" << endl;
    }
    int a;
    string b;
    double c;

};
int main(void){
    Tmp t1{1, "JUNHO", 2};
    cout << t1.a << " " << t1.b << " " << t1.c << endl;
    fstream outFile{ "/Users/jun/Desktop/oop2_clion/Chap11/t.dat", ios::binary | ios::out };
    if(outFile){
        outFile.write(reinterpret_cast<const char*>(&t1),sizeof(Tmp));
        cout << "Success write!" << endl;
    }
    outFile.close();

    Tmp t2;
    fstream inFile{"/Users/jun/Desktop/oop2_clion/Chap11/t.dat", ios::binary | ios::in };
    if(inFile){
        inFile.read(reinterpret_cast<char*>(&t2), sizeof(Tmp));
        cout << "Success read!---" << endl;
        cout << t2.a << " " << t2.b << " " << t2.c << endl;
    }
    inFile.close();


}