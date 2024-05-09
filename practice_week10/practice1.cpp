#include <iostream>
using namespace std;
class Derived;

class Base {
protected:
	int num1;
public:
	Base() : num1{ 10 } {}
	void baseShow() { cout << "Value of Number 1: " << num1 << endl; }
};

class Derived : public Base {
	friend void swap(Derived* d) {
		int temp = d->num1;
		d->num1 = d->num2;
		d->num2 = temp;
	}
protected:
	int num2;
public:
	Derived() : num2{ 20 } {}
	void show() {
		baseShow();
		cout << "Value of Number 2: " << num2 << endl;
	}
};

int main() {
	Derived d;
	d.show();

	swap(&d);

	d.show();
	return 0;
}