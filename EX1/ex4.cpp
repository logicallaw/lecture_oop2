#include <iostream>
using namespace std;
void MyHandler(){
    cout << "MyHandler" << endl;
    exit(EXIT_FAILURE);
}
int main(void){
    int n1{ 10 };
    int n2{ 0 };
    set_terminate(MyHandler);
    cout << "HI" << endl;
    try{
        if(n2 == 0){
            throw 0.1;
        }
    }
    catch(double){
        cout << "ERROR : Division by zero." << endl;
    }


}