#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
    int count;
public:
    Array(int size)
        : array{ new int[size]{} }, arraySize{ size }, count { 0 } {}
    void setter(int value){
        array[count++] = value;
    }
    void shift(int d){
        /*
         * counter = 0;
         *
         * int temp = array[counter];
         * array[++counter] = temp;
         *
         * */
        while(d--){
            int counter = 0;
            for (int i = 0; i < arraySize - 1; i++){
            }
        }
    }
    void switch1(const int& i, const int& j){}
    void print() const {}
};
int main(void){
    int t, n;
    cin >> t >> n;
    Array arr(n);
    int value;
    for (int i = 0; i < n; i++){
        cin >> value;
        arr.setter(value);
    }
    string userInput;
    while(t--){
        cin >> userInput;
        if (userInput == "shift"){
            int d;
            cin >> d;
            arr.shift(d);
        }
        else if (userInput == "switch"){
            int i, j;
            cin >> i >> j;
            arr.switch1(i,j);
        }
        else if (userInput == "print"){
            arr.print();
        }
    }
}