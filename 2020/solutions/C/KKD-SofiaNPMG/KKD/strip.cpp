#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

short n;
short k;

long long calc(int l, int r) {
    if (l == 1 && r == n) { return 1; }
    return ((l > 1) ? calc(l - 1, r) : 0) + ((r < n) ? calc(l, r + 1) : 0);
}

int main() {
    cin >> n >> k;
    cout << calc(k, k) << endl;
    return 0;
}
