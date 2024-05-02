#include <iostream>
using namespace std;

class Derived;

class Base {
	friend void swap(Base* b, Derived* d);
protected:
	int num1;
public:
	Base() : num1{ 10 } {}
	void show() { cout << "\n Value of Number 1 : " << num1; }
};

class Derived {
	friend void swap(Base* b, Derived* d);
protected:
	int num2;
public:
	Derived() : num2{ 20 } {}
	void show() { cout << "\n Value of Number 2 : " << num2; }
};

void swap(Base* b, Derived* d) {
	int temp = b->num1;
	b->num1 = d->num2;
	d->num2 = temp;
}

int main() {
	Base b;
	Derived d;
	b.show();
	d.show();

	swap(&b, &d);

	b.show();
	d.show();
	return 0;
}