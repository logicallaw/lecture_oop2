#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    char buffer[5];
    cin.read(buffer, 6);
    cout.write(buffer, cin.gcount());
}