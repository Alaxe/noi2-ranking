#include <iostream>
using namespace std;
#define endl '\n'
long long dp[64][64];
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, m, n;
    cin >> k >> m >> n;
    for (int i=1;i<m;i++) dp[1][i]=1;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<m;j++) {
            if (j>k) dp[i][j]=dp[i-1][j-k];
            if (j+k<m) dp[i][j]+=dp[i-1][j+k];
            ///cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    long long ans=0;
    for (int i=1;i<m;i++) ans+=dp[n][i];
    cout << ans << endl;
    return 0;
}
