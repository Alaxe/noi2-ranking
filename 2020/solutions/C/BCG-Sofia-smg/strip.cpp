#include <bits/stdc++.h>
using namespace std;

long long a[51][51];

int main () {

int n, k;
cin >> n >> k;

for (int i=0; i < n; i++) {
    a[i][0] = 1;
    a[i][i] = 1;
}

for (int i=0; i < n; i++) {
    for (int j=0; j <= i; j++) {
            if (j >= 1 and i >= 1 and j != i) {
                a[i][j] += a[i-1][j-1];
            }
            if (j <= i-1 and i >= 1 and j != 0) {
                a[i][j] += a[i-1][j];
            }
    }
}

cout << a[n-1][k-1] << endl;

return 0;
}
