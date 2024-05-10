#include <iostream>
using namespace std;
class Array{
private:
    int *arr;
    int arraySize;
public:
    Array(int size){ //배열 생성
        this->arraySize = size;
        this->arr = new int[arraySize];
        for (int i = 0; i < arraySize; i++){
            arr[i] = i;
        }
    }
    int at(int index){ //해당 위치 원소 리턴
        return arr[index];
    }
    void add(int index, int value){ //배열의 삽입
        for (int i = arraySize - 2; i >= index; i--){
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
    }
    void set(int index, int value){ //배열에 값 할당
        arr[index] = value;
    }
    void print(){ //배열 원소 차례로 출력
        for(int i = 0; i < arraySize; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void remove(int index){ //배열 원소 값 삭제 후 당기기
        for (int i = index + 1; i < arraySize; i++){
            arr[i - 1] = arr[i];
        }
        arr[arraySize - 1] = 0;
    }
};
int main(){
    int counter, size, index, value;
    string userInput;
    cout << "counter: ";
    cin >> counter;
    cout << "size: ";
    cin >> size;
    Array ar(size);
    while(counter--){
        cout << "Input(at, add, set, remove, print):";
        cin >> userInput;
        if (userInput == "at"){
            cout << "Input Index: ";
            cin >> index;
            cout << ar.at(index) << endl;
        }
        else if (userInput == "add"){
            cout << "Input Index, value: ";
            cin >> index >> value;
            ar.add(index, value);
        }
        else if (userInput == "set"){
            cout << "Input Index, value: ";
            cin >> index >> value;
            ar.set(index, value);
        }
        else if (userInput == "remove"){
            cout << "Input Index: ";
            cin >> index;
            ar.remove(index);
        }
        else if (userInput == "print"){
            ar.print();
        }
        else {
            cout << "error!" << endl;
        }
    }
    return 0;
}