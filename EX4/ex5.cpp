#include <iostream>
using namespace std;
int main(void){
    const char* word = "OOP2";
    cout << word << endl;
    for (int i{ 0 }; i < strlen(word); i++){
        cout << static_cast<int>(word[i]) << " ";
    }
}