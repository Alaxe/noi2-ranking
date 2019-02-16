
#include <iostream>

using namespace std;

long long dp[70][70];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k, m, n;
    cin >> k >> m >> n;
    for(int i = 1; i < m; i ++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j < m; j ++) {
            if(j - k > 0)
                dp[i][j] += dp[i - 1][j - k];
            if(j + k < m)
                dp[i][j] += dp[i - 1][j + k];
//            cout << dp[i][j] << " ";
        }
//    cout << endl;
    }
    long long ans = 0;
    for(int i = 0; i < m; i ++)
        ans += dp[n][i];
    cout << ans << "\n";
}
