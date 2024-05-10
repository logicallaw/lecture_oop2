#include <iostream>
using namespace std;
class order{ //abstract class
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
    virtual void changeAddress()=0; //pure virtual function.
};

class chickenOrder: public order { //abstract class
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
    virtual void changeAddress() override {
        cout << "Input new address: ";
        cin >> address;
        cout << "The pizzaOrder class successfully changed the address." << endl;
    }
};

class pizzaOrder: public chickenOrder {
private:
    int price;
    string address;
public:
    pizzaOrder(int p, string addr) : price{ p }, address{ addr } {
        cout << "A pizza order: $" << price << " to " << address << " has been created" << endl;
    }
    //Override here!
    virtual void changePrice(int newPrice) override {
        price = newPrice;
        cout << "The pizzaOrder class successfully changed the price." << endl;
    }
    virtual void display() override {
        cout << "The price: $" << price << ", the address: " << address << "." << endl;
    }
    virtual void changeAddress() override{
        cout << "Input new address: ";
        cin >> address;
        cout << "The pizzaOrder class successfully changed the address." << endl;
    }
};

int main(void){
    chickenOrder chickenObject{ 300, "Inha"};
    pizzaOrder pizzaObject{ 400, "Office"};

    cout << endl;
    chickenObject.changeAddress();
    pizzaObject.changeAddress();

    cout << endl;
    chickenObject.display();
    pizzaObject.display();

    return 0;
}