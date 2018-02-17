#include<bits/stdc++.h>

using namespace std;

int dpt[10000][2] = {0}, p, q, MOD;

int dp(int rem, int ok)
{
    if (rem <= 0)
        return 1;
    if (dpt[rem][ok]) return dpt[rem][ok] % MOD;

    if (ok)
        return dpt[rem][ok] = dp(rem - p, 0) % MOD;

    int v = dp(rem - p, 0) % MOD;
    v += dp(rem + q, 1) % MOD;

    return dpt[rem][ok] = v % MOD;
}

int main()
{
    MOD = (1 << 30);

    int n, m;

    cin >> n >> m >> p >> q;

    cout << dp(m - n, 1) << endl;

    return 0;
}
