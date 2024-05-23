#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream inText{ "FileName.cpp", ios::in };
	int countChars = 0;
	int countLine = 0;
	string line;
	while (getline(inText, line)) {
		cout << line << endl;
		countChars += line.length();
		countLine++;
	}
	cout << "The total number of characters is " << countChars + countLine - 1 << "." << endl;
	cout << "The number of lines is " << countLine << endl;
	return 0;
}