#include <iostream>
using namespace std;
int main(void){
    const int SIZE{ 80 };
    char buffer[SIZE];

    cout << "Enter a sentence\n";
    cin.read(buffer, 20);

    cout << "\nThe sentence entered was:\n";
    cout.write(buffer, cin.gcount());
    cout << endl;
}
