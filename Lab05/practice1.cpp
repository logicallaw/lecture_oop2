#include <iostream>
#include <vector>
using namespace std;
class order {
private:
    int cheese;
    int peperoni;
    int sausage;
    int mushroom;
    string customerName;
    string address;
public:
    void set(int c, int p, int s, int m, string name, string address);
    void set(string name, string address);
    void set(string name, string address, int c, int p, int s, int m);
    void display () ;
};
//Define here
void order::set(int c, int p, int s, int m, string name, string address){
    cheese = c;
    peperoni = p;
    sausage = s;
    mushroom = m;
    customerName = name;
    this->address = address;
}
void order::set(string name, string address) {
    set(0, 0, 0, 0, name, address);
}
void order::set(string name, string address, int c, int p, int s, int m) {
    set(c, p, s, m, name, address);
}

class pizzaOrder {
private:
    vector <order*> orders; //order타입의 포인터 배열. 각 원소는 포인터이다.
public:
    void add(order* o){ orders.push_back(o); }
    void display();
};

void order::display() {
    cout << "Name："<< customerName <<
         " Address: " << address <<
         " cheese： " << cheese <<
         " peperoni: " << peperoni <<
         " sausage: " <<sausage <<
         " mushroom: "<< mushroom << endl;
}

void pizzaOrder::display() {
    for (int i = 0; i < orders.size(); i++) {
        orders[i]->display(); //orders의 원소는 포인터라 멤버함수에 접근하려면 Arrow operator를 사용해야한다.
    }
}
int main () {
    pizzaOrder orders;

    order o1, o2, o3;
    o1.set(0, 0, 0, 0, "Bart", "New York");
    orders.add(&o1);

    o2.set("Lisa", "New York");
    orders.add(&o2);

    o3.set("Homer", "New York", 10, 10, 10, 10);
    orders.add(&o3);
    orders.display();
    return 0;
}