#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    sort(a, a + n);
    bool ok = true;
    for (int c = 1; true; ++ c) {
        ok = true;
        long long b = c * c;
        for (int j = 0; j < n; ++ j) {
            if (b % a[j] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) { cout << c << endl; break; }
    }
    return 0;
}
