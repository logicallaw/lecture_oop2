#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int n)
        : array{ new int[n]{} }, arraySize{ n } {}
    void at(const int& i){
        cout << array[i] << "\n";
    }
    void add(const int& index, const int& z){
        for(int i = arraySize - 2; i >= index; i--){
            array[i + 1] = array[i];
        }
        array[index] = z;
    }
    void set(const int& i, const int& z){
        array[i] = z;
    }
    void find(const int& z){
        for (int i = 0; i < arraySize; i++){
            if (array[i] == z){
                cout << i << endl;
                return;
            }
        }
        cout << "-1" << "\n";
    }
    void remove(int index){
        for (int i = arraySize - 2; i >= index; i--){
            array[i] = array[i + 1];
        }
        array[arraySize - 1] = 0;
    }
    void print() const {
        for (int i{ 0 }; i < arraySize; i++){
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

int main(void){
    int t, n;
    cin >> t >> n;
    Array arr{n};
    while(t--){
        string userInput;
        cin >> userInput;
        if (userInput == "at"){
            int i;
            cin >> i;
            arr.at(i);
        }
        else if (userInput == "add"){
            int i, z;
            cin >> i >> z;
            arr.add(i,z);
        }
        else if (userInput == "set"){
            int i, z;
            cin >> i >> z;
            arr.set(i, z);
        }
        else if (userInput == "remove"){
            int i;
            cin >> i;
            arr.remove(i);
        }
        else if(userInput == "find"){
            int z;
            cin >> z;
            arr.find(z);
        }
        else if (userInput == "print") {
            arr.print();
        }
    }
    return 0;
}