#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	ifstream inText{ argv[1] };
	int countChars = 0;
	int countLine = 0;
	string line;
	while (getline(inText, line)) {
		cout << line << endl;
		countChars += line.length();
		countLine++;
	}
	inText.close();
	cout << "The total number of characters is " << countChars + countLine - 1 << "." << endl;
	cout << "The number of lines is " << countLine << endl;
	return 0;
}