#include <iostream>
using namespace std;

int totalMemoryFootPrint = 0;
int integerMemoryFootPrint = 0;

template<typename T>
T* mem(T num){
    totalMemoryFootPrint += num * sizeof(T);
    return new T{ num };
}

template<>
int* mem(int num){
    totalMemoryFootPrint += num * sizeof(int);
    integerMemoryFootPrint += num * sizeof(int);
    return new int{ num };
}

int main(void){
    char* cdata;
    int* idata;
    double* ddata;

    cdata = mem<char>(2); //2 byte
    idata = mem<int>(2); //8 byte
    ddata = mem<double>(3); //24 byte
    // print the global memory footprint and memory footprint only of integers.
    cout << "totalMemoryFootPrint : " << totalMemoryFootPrint << endl;
    cout << "integerMemoryFootPrint : " << integerMemoryFootPrint << endl;
    return 0;
}