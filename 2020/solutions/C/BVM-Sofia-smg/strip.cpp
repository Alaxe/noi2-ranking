#include <bits/stdc++.h>
using namespace std;
long long dp[64][64];
int n, k;
int main () {
    for (int i = 1 ; i < 64 ; ++i) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 1 ; i < 64 ; ++i) {
        for (int j = 1 ; j < 64 ; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    scanf("%d%d", &n, &k);
    printf("%lld\n", (dp[k-1][n-k]));
    return 0;
}
