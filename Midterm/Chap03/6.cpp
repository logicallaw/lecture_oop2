#include <iostream>
using namespace std;
class Student{
private:
    int math;
    int kor;
    int eng;
    static int counter;
public:
    Student(){
        counter++;
    };
    Student(int math, int kor, int eng)
        : math{ math }, kor{ kor }, eng{ eng }{}
        int getMath() const { return math; }
        int getKor() const { return kor; }
        int getEng() const { return eng; }
    static int getCounter();
};

class Math{
private:
    int result;
public:
    Math();
    Math(int math, int kor, int eng){

    }
    Math& add(){
        return *this;
    }
};
int Student::counter{1};
int Student::getCounter(){ return counter++;}

int main(void){
    int size;
    cout << "Input size: ";
    cin >> size;
    Student* students = new Student[size];

    for (int i{ 0 }; i < size; i++){
        int math, kor, eng;
        cout << "Input " << Student::getCounter() << "번째: ";
        cin >> math >> kor >> eng;
        students[i] = Student{math, kor, eng};
    }

    cout << endl;
    for (int i = 0; i < size; i++){
        int math = students[i].getMath();
        int kor = students[i].getKor();
        int eng = students[i].getEng();
        Math temp{ math, kor, eng };
    }



}