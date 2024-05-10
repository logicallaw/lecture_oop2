#include <iostream>
using namespace std;
class Stack{ //abstract class
private:
public:
    virtual int length() const=0;
    virtual int capacity() const=0;
    virtual string pop()=0;
    virtual bool push(string str)=0;
};

class StringStack:public Stack{ //concrete class
private:
    string* pstk;
    int size;
    int tos;
public:
    StringStack(int size)
        : pstk{ new string[size] }, tos{ 0 }, size{ size } {}
    //overriding
    virtual int length() const override{ return tos + 1; }
    virtual int capacity() const override{ return size; }
    virtual string pop() override{
        return pstk[--tos];
    }
    virtual bool push(string userInput) override{
        if (tos < size){
            pstk[tos++] = userInput;
            return true;
        } else {
            cout << "false" << endl;
            return false;
        }
    }
};

int main(void){
    int size;
    cout << "size of stack: ";
    cin >> size;
    StringStack stk{ size };
    string userInput;
    cout << "input: ";
    cin >> userInput;
    while(userInput != "exit"){
        bool pass = stk.push(userInput);
        if (!pass){
            cout << "stack is full!" << endl;
        }
        cout << "input: ";
        cin >> userInput;
    }

    cout << "pop all strings: ";
    for (int i = 0; i < stk.capacity(); i++)
        cout << stk.pop() << " ";


    return 0;
}