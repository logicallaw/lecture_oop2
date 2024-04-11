#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++) {

        int j = num - i;

        while (j >= 1) {
            cout << " " << setw(3);
            j--;
        }

        int k = 1;
        while (k <= i) {
            cout << k << setw(3);
            k++;
        }
        cout << 두ㅇ;
    }

    cout << setw(3) << 2;
    return 0;
}
//int main(void){
//    int n;
//    cin >> n; //3:3,2,1
//
//    //n번 출력합니다.
//    for (int num{ 1 }; num <= n; num++){
//        //n-num번 만큼 " "을 출력합니다.
//        for (int index { 0 }; index < n - num; index++){
//            cout << setw(3) << setfill(' ') << " ";
//        }
//        for (int index{ 1 }; index <= num; index++) {
//            cout << setw(3) << left << setfill(' ') << index;
//        }
//        cout << endl;
//    }
//    return 0;
//}