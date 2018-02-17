#include <bits/stdc++.h>

using namespace std;

int MAX;
void breakNumber(int number) {
    cout << number << " ";

    if (number == 1)
        return;

    for (int i = number - 1; i >= 1; i--) {
        breakNumber(i);
        cout << "\n";
    }
}

int main() {

    MAX = 5;
    breakNumber(6);



    return 0;
}
