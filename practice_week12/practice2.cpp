#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void) {
	ifstream inText1{ "text1.txt", ios::in };
	ifstream inText2{ "text2.txt", ios::in };
	ofstream inText3{ "text3.txt", ios::out };
	string line;
	try {
		//Read Text1.txt
		while (getline(inText1, line)) {
			inText3 << line << endl;
		}
		//Read Text2.txt
		while (getline(inText2, line)) {
			inText3 << line << endl;
		}
	}
	catch (...) {
		cout << "error!" << endl;
	}
	inText3.close();
	inText2.close();
	inText1.close();
	cout << "Success!" << endl;
	return 0;
}