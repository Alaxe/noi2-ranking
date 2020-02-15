#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 1000000000;

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        for (int j = 1; j <= 10000; j++) {
            dp[j] = min(dp[j-1], dp[j]+abs(a-j));
        }
    }
    cout << dp[10000] << endl;

    return 0;
}
