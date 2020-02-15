#include <iostream>
using namespace std;
int k, n, ans[1000];
int main () {
    cin >> n >> k;
    n--;
    int l = k - 1;
    ans[0] = 1;
    for (int i = 1; i < 1000; i++) {
        ans[i] = -1;
    }
    for (int i = 0; i < l; i++) {
        int mult = n - i;
        int prenos = 0;
        for (int o = 0; ; o++) {
            if (ans[o] == -1 && prenos == 0) {
                break;
            }
            if (ans[o] == -1) {
                ans[o] = 0;
            }
            ans[o] = ans[o] * mult + prenos;
            prenos = ans[o] / 10;
            ans[o] = ans[o] % 10;
        }
    }

    int cifri;
    for (int i = 0; ; i++) {
        if (ans[i] == -1) {
            cifri = i;
            break;
        }
    }
    int newNumber[cifri];
    for (int i = cifri - 1; i >= 0; i--) {
        newNumber[cifri - 1 - i] = ans[i];
        ///cout << newNumber[cifri - 1 - i];
    }
    //cout << endl;

    for (int i = l; i > 0; i--) {
        int del = i;
        int prenos = 0;
        for (int o = 0; o < cifri; o++) {
            prenos *= 10;
            newNumber[o] += prenos;
            prenos = newNumber[o] % del;
            newNumber[o] /= del;
        }
    }
    bool pochna = false;
    for (int i = 0; i < cifri; i++) {
        if (!pochna && newNumber[i] != 0) {
            pochna = true;
        }
        if (pochna) {
            cout << newNumber[i];
        }
    }
    return 0;
}
