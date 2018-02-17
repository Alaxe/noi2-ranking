#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1073741824;

ll M, N, p, q;
ll dp[10002][2];

ll F(ll gr, bool f)
{
    if (gr >= N) return 1;
    if (f)
    {
        if (dp[gr][1] != -1) return dp[gr][1];
    }
    else if (dp[gr][0] != -1) return dp[gr][0];

    ll ans = 0;

    ans = (ans + F(gr + p, true)) % MOD;
    if (f) ans = (ans + F(gr - q, false)) % MOD;
    if (f) dp[gr][1] = ans;
    else dp[gr][0] = ans;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));

    cin >> M >> N >> p >> q;

    cout << F(M, false) << '\n';

    return 0;
}
