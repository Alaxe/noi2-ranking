#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int t;
    while (b) {
        t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int main() {
    int n, m = 1;
    cin >> n;
    int arr[n];
    int nod = 1, k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i != 0) {
            k = gcd(arr[i - 1], arr[i]);
            nod *= k;
        }
        m *= arr[i];
    }
    int nok;
    nok = m / nod;
    for (unsigned long long i = nok; true; i += nok) {
        double l;
        l = sqrt(i);
        int j;
        bool h1 = false, h2 = false, h3 = false;
        l *= 10;
        j = l;
        if (j % 10 == 0) {
            h1 = true;
        }
        l *= 10;
        j = l;
        if (j % 10 == 0) {
            h2 = true;
        }
        l *= 10;
        j = l;
        if (j % 10 == 0) {
            h3 = true;
        }
        if (h1 && h2 && h3) {
            cout << (j / 1000) << endl;
            return 0;
        }
    }

    return 0;
}
