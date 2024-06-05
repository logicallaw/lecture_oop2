#include <iostream>
#include <string>
using namespace std;
template <typename T1, typename T2>
class GenericPair{
private:
    T1 t1;
    T2 t2;
public:
    GenericPair(T1 first, T2 second)
        : t1{ first }, t2{ second } {}
    T1 getFirst() const { return t1; }
    T2 getSecond() const { return t2; }
    void setFirst(T1 first) { t1 = first; }
    void setSecond(T2 second) { t2 = second; }
};

template<>
class GenericPair<int, string>{
private:
  int t1;
  string t2;
public:
    GenericPair(int first, string second)
        : t1{ 0 }, t2{ "HAHA" } {}
    int getFirst() const { return 0; }
    string getSecond() const{ return "HAHA"; }
    void setFirst(int first){ t1 = 0; }
    void setSecond(string second) { t2 = "HAHA"; }
};

int main(void){
    GenericPair<int, string> pair(1, "apple");
    cout << pair.getFirst() << endl;
    cout << pair.getSecond() << endl;
    pair.setFirst(2);
    pair.setSecond("orange");
    cout << pair.getFirst() << endl;
    cout << pair.getSecond() << endl;
}