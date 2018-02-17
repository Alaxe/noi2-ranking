#include <iostream>
using namespace std;

int main () {
    long long n, i, j;
    cin >> n;
    char A[n][n], a;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin >> A[i][j] >> a;
        }
    }
    cout << (2*n-2)*11+3 << endl;

return 0;
}
