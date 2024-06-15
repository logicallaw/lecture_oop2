#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{"words.txt", ios::in};
    string word;
    while(inFile >> word){
        int acount = 0;
        int Acount = 0;
        for (int i = 0; i < word.length(); i++){
            if('a' == word[i]){
                acount++;
            }
            else if ('A' == word[i]){
                Acount++;
            }
            if(acount == 5 || Acount == 5){
                cout << word << endl;
                break;
            }
        }
    }
    inFile.close();
}