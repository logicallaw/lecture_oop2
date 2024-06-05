#include <iostream>
using namespace std;
template<typename T>
class GenericStack{
private:
    T array[100];
    int index = 0;
    int arraySize = 0;
public:
    void push(T value){
        arraySize++;
        array[index++] = value;
    }
    T pop(){
        arraySize--;
        return array[--index];
    }
    T top() const {
        return array[index - 1];
    }
    bool isEmpty() const{
        return (index + 1 <= 0) ? true : false;
    }
    int size() const {
        return arraySize;
    }
};

int main(void){
    GenericStack<int> stack;
    stack.push(10);
    stack.push(20);
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.isEmpty() << endl;
    cout << stack.size() << endl;
    return 0;
}