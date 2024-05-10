#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int size)
        : array{ new int[size]{} }, arraySize{ size } {}
    void at(int index){
        cout << array[index] << endl;
    }
    void add(int index, int value){
        for (int i = arraySize - 2; i >= index; i--){
            array[i + 1] = array[i];
        }
        array[index] = value;
    }
    void remove(int index){
        for (int i = arraySize - 2; i >= index; i--){
            array[i] = array[i + 1];
        }
        array[arraySize - 1] = 0;
    }
    void set(int index, int value){
        array[index] = value;
    }
    void find_max() const{
        int max = array[0];
        for(int i = 1; i < arraySize; i++){
            max = (max < array[i]) ? array[i] : max;
        }
        cout << max << endl;
    }
    void print() const {
        for(int i = 0; i < arraySize; i++){
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

int main(void){
    int t, n;
    cin.tie();
    cin >> t >> n;
    Array arr(n);

    int index, value;
    while(t--){
        string userInput;
        cin >> userInput;
        if (userInput == "at"){
            cin >> index;
            arr.at(index);
        }
        else if (userInput == "add"){
            cin >> index >> value;
            arr.add(index, value);
        }
        else if (userInput == "remove"){
            cin >> index;
            arr.remove(index);
        }
        else if (userInput == "set"){
            cin >> index >> value;
            arr.set(index, value);
        }
        else if (userInput == "print"){
            arr.print();
        }
        else if (userInput == "find_max"){
            arr.find_max();
        }
    }
    return 0;
}