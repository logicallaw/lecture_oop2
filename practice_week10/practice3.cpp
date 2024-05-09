#include <iostream>
using namespace std;
class Base {
public:
	int f(int n) { 
		cout << "f(int) in base: ";
		return n + 3; 
	}
	double f(double n) {
		cout << "f(double) in base: ";
		return n * 2 - 0.1;
	}
};

class Derived : public Base {
public:
	int f(int n) { 
		cout << "f(int) in derived: ";
		return n + 4;
	}
	double f(double n) { 
		cout << "f(double) in derived: ";
		return n * 2; 
	}
};

int main(void) {
	Derived* dp = new Derived;
	cout << dp->f(3) << endl;
	cout << dp->f(3.3) << endl;

	Base* bp = dp;
	cout << bp->f(4) << endl;
	cout << bp->f(4.4) << endl;
	delete dp;
	return 0;
}