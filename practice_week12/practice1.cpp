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
	//개행문자('\n')를 고려하여 character 개수를 출력합니다.
	if (countLine > 1) {
		cout << "The total number of characters is " << countChars + countLine - 1 << "." << endl;
	}
	else { //countLine = 0 또는 1
		cout << "The total number of characters is " << countChars << "." << endl;
	}
	
	cout << "The number of lines is " << countLine << endl;
	return 0;
}