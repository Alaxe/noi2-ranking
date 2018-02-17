#include <iostream>
using namespace std;
int main() {

    long long n;
    cin >> n;
    long long flower[n], q;

    for (int i = 0; i < n; i++) {           //cin-�� ������ �����
        cin >> flower[i];
    }

    cin >> q;
    long leftover_mm = 0, biggest_so_far = 0;

    for (int i = 0; i < n; i++) {          //������ ���-�������� �����
        if (flower[i] > biggest_so_far) {
            biggest_so_far = flower[i];
        }
    }

    for (int i = 0; i < n; i++) {                                   //������ ����� �� ������ �� ��������� ������� �� �� �� �����
        leftover_mm = leftover_mm + (biggest_so_far - flower[i]);
    }
    cout << leftover_mm * q;            //������ ���������� �� * ����� ���� �� 1��

    return 0;
}
