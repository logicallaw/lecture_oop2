#include <iostream>
using namespace std;
class order{
private:
    int price;
    string address;
public:
    order() = default;
    order(int p, string addr) : price{ p }, address{ addr } {
        cout << "An order: $" << price << " to " << address << " has been created." << endl;
    }
    virtual void changePrice(int newPrice) {
        cout << "The basic order class does not allow to change the price" << endl;
    }
    virtual void display() {
        cout << "The basic order class does not allow to display the price" << endl;
    }
};

class chickenOrder: public order {
private:
    int price;
    string address;
public:
    chickenOrder() = default;
    chickenOrder(int p, string addr) : price{ p }, address{ addr } {
        cout << "A chicken order: $" << price << " to " << address << " has been created." << endl;
    }
    //Overriding functions here!
    virtual void changePrice(int newPrice) override {
        price = newPrice;
        cout << "It was successfully changed." << endl;
    }
    virtual void display() override {
        cout << "The price: $" << price << ", the address: " << address << "." << endl;
    }
};

int main(void){
    order orderObject{ 200, "Home" };
    chickenOrder chickenObject{ 300, "Inha"};

    cout << endl;
    orderObject.changePrice(400);
    chickenObject.changePrice(600);

    cout << endl;
    orderObject.display();
    chickenObject.display();
    return 0;
}