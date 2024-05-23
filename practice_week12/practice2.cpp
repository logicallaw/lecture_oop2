#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream inText1{"text1.txt", ios::in};
	ifstream inText2{"text2.txt", ios::in};
	ofstream inText3{"text3.txt", ios::out};
	string line;

	//Read Text1.txt
	while (getline(inText1, line)) {
		inText3 << line << endl;
	}
	//Read Text2.txt
	while (getline(inText2, line)) {
		inText3 << line << endl;
	}
	return 0;
}