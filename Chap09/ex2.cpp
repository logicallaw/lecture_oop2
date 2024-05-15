#include <iostream>
using namespace std;
int main(){
    int select;
    try{
        cin >> select;
        switch(select){
            case 1:
                throw 1;
                break;
            case 2:
                throw 'a';
                break;
            default:
                throw 1.5;
                break;
        }
    }
    catch(int){
        cout << "error:int" << endl;
    }
    catch(char){
        cout << "error:char" << endl;
    }
    catch(...){
        cout << "error:multiple catch blocks" << endl;
    }
    return 0;

}