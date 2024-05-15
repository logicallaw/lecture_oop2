#include <iostream>
using namespace std;
int main() {
    int number1{ 5 };
    int number2{ 0 };
    try{
        if(number2 == 0){
            throw number2;
        }
        else{
            cout << number1 / number2 << endl;
        }
    }
    catch(int){
        cout << "error!" << endl;
    }

    return 0;
}
