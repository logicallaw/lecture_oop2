#include <iostream>
using namespace std;
int main(void){
    const int SIZE = 80;
    char buffer[SIZE];
    cin.read(buffer, 20);
    cout.write(buffer, cin.gcount());
}