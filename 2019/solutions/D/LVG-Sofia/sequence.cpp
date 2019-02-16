#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long br = 1;
    unsigned long long f = 0, i;
    for (i = 1; i <= (n * 2 - 1); i += 2) {
        f += i;
    }
    if (k == 1) {
        f -= (n - 1);
        cout << f << endl;
        return 0;
    }
    for (; br < k; i += 2) {
        f += i;
        br += 2;
    }
    if (br == k) {
        f -= (n - 1);
        cout << f << endl;
        return 0;
    }
    if (br - 1 == k) {
        f -= ((((i + 1) / 2) - n - 1) * 2 + 1);
        br--;
        cout << f << endl;
        return 0;
    }
    i -= 2;
    f -= ((((i + 1) / 2) - n - 1) * 2 + 2);
    cout << f << endl;

    return 0;
}
