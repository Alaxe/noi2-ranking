#include <iostream>
using namespace std;

unsigned long long k, m, n, i, j, f, a[100][100], br;

int main () {
    cin >> k >> m >> n;
    for (i = 1; i < m; i ++) {
        for (j=1;j<=n;j++) {
            for (f=1;f<=m;f++) {
                a[j][f]=0;
            }
        }
        a[1][i] = 1;
        for (j = 1; j <= n; j ++) {
            for (f = 1; f < m; f ++) {
                if (f - k >= 0) a[j][f] += a[j-1][f-k];
                if (f + k < m) a[j][f] += a[j-1][f+k];
                if (j == n) br += a[j][f];
            }
        }
    }
    cout << br << endl;
    return 0;
}
