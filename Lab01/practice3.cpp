#include <iostream>
using namespace std;
void printMaxMin(int nums[]); //pass-by-reference, �ִ񰪰� �ּڰ��� ã�Ƽ� ����ϴ� �����Լ�.

int main(void) {
    int nums[5];
    cout << "Please type five numbers.\n";
    for (int i{ 0 }; i < 5; i++)
        //������ �������� 5�� ������ �Է¹޾� �迭 nums�� �����Ѵ�.
        cin >> nums[i];

    //nums �迭�� ����մϴ�.
    cout << "The input was ";
    for (int i{ 0 }; i < 5; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    //�ִ񰪰� �ּڰ��� ����մϴ�.
    printMaxMin(nums);
    return 0;
}

void printMaxMin(int nums[]) {
    int min = nums[0];
    int max = nums[0];
    for (int i{ 1 }; i < 5; i++) {
        min = (min >= nums[i]) ? nums[i] : min;
        max = (max <= nums[i]) ? nums[i] : max;
    }
    cout << "Max: " << max << " Min: " << min;
}