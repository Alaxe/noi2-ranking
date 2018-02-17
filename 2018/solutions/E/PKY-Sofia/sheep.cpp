#include <iostream>
using namespace std;
int main() {

    long long n, l;
    bool is_this_number_correct = true;
    cin >> n >> l;
    int missing_digits[l], numbers_so_far_that_are_correct = 0, number_for_checking;
    for (int i = 0; i < l; i++) {       //cin-�� ������ �������� ������
        cin >> missing_digits[i];
    }

    for (number_for_checking = 1; numbers_so_far_that_are_correct < n; number_for_checking++) {     //�����, ����� ������� ot 1 � ����� ������ ��� �������� n �������� �����
        is_this_number_correct = true;
        int a_copy_of_the_number_we_are_checking = number_for_checking;
        for (int i = 0; i < l; i++) {       //�����, ����� ����� �� ���������� �� ����� �������� ����� � ����� ����� �� ��������� �����
            if (number_for_checking % 10 == missing_digits[i] or number_for_checking / 10 == missing_digits[i]or number_for_checking / 100 == missing_digits[i] or number_for_checking / 1000 == missing_digits[i] or number_for_checking / 10000 == missing_digits[i] or number_for_checking / 100000 == missing_digits[i] or number_for_checking / 1000000 == missing_digits[i]) {            //�������� �� ���� ����� �� ��������� �����
                is_this_number_correct = false;
            }
        }
        a_copy_of_the_number_we_are_checking = a_copy_of_the_number_we_are_checking / 10;
        if (is_this_number_correct) {       //���������� ���� ������� ���� �� �� �������, � ��� ���� ������ ���� ��� ���� �� ���������� �����
            numbers_so_far_that_are_correct++;
        }
    }
    cout << number_for_checking - 1;    //������ ���������� ��� 1 ������ ������ ��-���� ����� ����, ����� ���� ������, ��� ������ ��� ������������, �� ���� ��� �� �� ��������� ���� ������ ���� � ������ ���������


    return 0;

}
