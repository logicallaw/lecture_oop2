#include <iostream>
using namespace std;
int main(){
    try{
        try{
            throw 1.5;
        }
        catch(int e){
            cout << "inner: " << e << endl;
        }
        catch(...){
            cout << "inner: rethrow" << endl;
            throw;
        }
    }
    catch(double e){
        cout << "outer: " << e << endl;
    }
    catch(double d){
        cout << "outer2: " << d << endl;
    }

}