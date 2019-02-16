#include <iostream>
using namespace std;
int main () {
    unsigned long long a, b, counter, counter1,counterdelitel, delitel;
    cin >> a >> b;
    delitel = 1;
    counter1 = a;
    counter = 0;
    while (counter1 <= b) {
        while (delitel <= counter1) {
            if (counter1 % delitel == 0) {
                counterdelitel++;
            } else {
                counterdelitel = counterdelitel;
            }
        if (counterdelitel % 2 == 0) {
            counter++;
    }
                delitel++;
        }

        counterdelitel = 0;
        counter1++;

    }
    cout << counter <<endl;
}
