#include <iostream>
using namespace std;
int main() {

    long long n, k, smallest_n_digit_num = 1;
    cin >> n >> k;
    for (int i = 1; i < n; i++){ // ������ ���-������� n-������� �����
         smallest_n_digit_num = smallest_n_digit_num * 10;
    }

    if (smallest_n_digit_num % k == 0) {        //��������� ���� ���-������� n-������� ����� �� ���� �� �
        cout << smallest_n_digit_num;
    } else if (smallest_n_digit_num - (smallest_n_digit_num % k) + k < smallest_n_digit_num * 10){ //��������� ���� � ��������
        cout << smallest_n_digit_num - (smallest_n_digit_num % k) + k; // ������ (���-�������� n-1 ������� �����, ����� �� ���� �� �) + �
    } else {
        cout << "NO";
    }

    return 0;
}
