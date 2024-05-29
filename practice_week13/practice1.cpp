#include <iostream>
#include <string>
using namespace std;
int main(void){
    bool isIncluded = false;
    string userInput;
    try{
        cout << "Enter Email Id : ";
        cin >> userInput;
        for(int i{ 0 }; i < userInput.length(); i++){
            if(userInput[i] == '@'){
                isIncluded = true;
                break;
            }
        }
        if(!isIncluded){
            throw 0;
        }
    } catch(int) {
        cout << "Exception Caught..." << endl;
        cout << "Invalid Email Id!!!";
        exit(EXIT_FAILURE);
    }
    cout << "Email Id is Valid.";
    return 0;
}