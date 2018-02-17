#include <iostream>
using namespace std;
int main() {

    long long n, k, smallest_n_digit_num = 1;
    cin >> n >> k;
    for (int i = 1; i < n; i++){ // намира най-малкото n-цифрено число
         smallest_n_digit_num = smallest_n_digit_num * 10;
    }

    if (smallest_n_digit_num % k == 0) {        //проверява дали най-малкото n-цифрено число се дели на к
        cout << smallest_n_digit_num;
    } else if (smallest_n_digit_num - (smallest_n_digit_num % k) + k < smallest_n_digit_num * 10){ //проверява дали е възможно
        cout << smallest_n_digit_num - (smallest_n_digit_num % k) + k; // печати (най-голямото n-1 цифрено число, което се дели на к) + к
    } else {
        cout << "NO";
    }

    return 0;
}
