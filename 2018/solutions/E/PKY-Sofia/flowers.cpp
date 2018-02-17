#include <iostream>
using namespace std;
int main() {

    long long n;
    cin >> n;
    long long flower[n], q;

    for (int i = 0; i < n; i++) {           //cin-ва всички цветя
        cin >> flower[i];
    }

    cin >> q;
    long leftover_mm = 0, biggest_so_far = 0;

    for (int i = 0; i < n; i++) {          //намира най-голямото цвете
        if (flower[i] > biggest_so_far) {
            biggest_so_far = flower[i];
        }
    }

    for (int i = 0; i < n; i++) {                                   //намира колко мм трябва да порастнат цветята за да са равни
        leftover_mm = leftover_mm + (biggest_so_far - flower[i]);
    }
    cout << leftover_mm * q;            //печати оставащите мм * капки вода за 1мм

    return 0;
}
