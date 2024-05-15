#include <iostream>
#include <stdexcept>
using namespace std;
int main(void){
    try{
        throw out_of_range{"error!"};
    }
    catch(const out_of_range& e){
        cout << "out_of_range: " << e.what() << endl;
    }
    catch(const logic_error& e){
        cout << "logic_error: " << e.what() << endl;
    }
    catch(const exception& e){
        cout << "exception: " << e.what() << endl;
    }
}