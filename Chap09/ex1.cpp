#include <iostream>
#include <exception>
using namespace std;

void MyHandler() {
    cout << "My handler" << endl;
    exit(EXIT_FAILURE);
}

int main() {
    int number1{5};
    int number2{0};
    set_terminate(MyHandler);
    try{
        if(number2 == 0)
            throw 'a';
        else
            cout << number1 / number2 << endl;
    }
    catch(char){
        cout << "error" << endl;
        throw 'a';
    }
    catch(char){
        cout << "error2" << endl;
    }
    return 0;
}