#include <iostream>
using namespace std;

class Count {
protected:
	int chickens[3];
	int total;
public:
	void accept_details() {
		cout << "\n Enter the Number of Each Item to Order ";
		cout << "\n ------------------------------- \n";
		cout << "\n BBQ Chicken : ";
		cin >> chickens[0];
		cout << "\n Korean Spicy Chicken : ";
		cin >> chickens[1];
		cout << "\n Soybean Sauce Chicken : ";
		cin >> chickens[2];
	}
};
class Price : public Count {
protected:
	int prices[3];
public:
	void fix_order() {
		total = 0;
		for (int chicken : chickens) {
			total += chicken;
		}
		prices[0] = 100;
		prices[1] = 5;
		prices[2] = 10;
	}
};
class Order : public Price {
private:
	int totalPrice;
public:
	void calculate_price() {
		totalPrice = chickens[0] * prices[0];
		totalPrice += chickens[1] * prices[1];
		totalPrice += chickens[2] * prices[2];
	}
	void show_result() {
		cout << "\n ------------------------------- \n";
		cout << "\n Total Count: " << total;
		cout << "\n Total Price : " << totalPrice;
	}
};
int main() {
	Order p;
	p.accept_details();
	p.fix_order();
	p.calculate_price();
	p.show_result();
	return 0;
}