#include <bits/stdc++.h>

using namespace std;

const int maxn = 203;

bool dp[maxn][maxn], nxt_dp[maxn][maxn];
int n, w1, w2, a[maxn];
void read()
{
    cin >> n >> w1 >> w2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solve()
{
    for (int i = 0; i <= w1; i++)
        for (int j = 0; j <= w2; j++)
            dp[i][j] = false;

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w1; j++)
            for (int k = 0; k <= w2; k++)
            {
                if (dp[j][k] || (j-a[i] >= 0 && dp[j-a[i]][k]) || (k-a[i] >= 0 && dp[j][k-a[i]]))
                    nxt_dp[j][k] = true;

                else
                    nxt_dp[j][k] = false;
            }

        for (int j = 0; j <= w1; j++)
            for (int k = 0; k <= w2; k++)
                dp[j][k] = nxt_dp[j][k];
    }

    int ans = 0;
    for (int i = 0; i <= w1; i++)
        for (int j = 0; j <= w2; j++)
            if (dp[i][j])
                ans = max(ans, i + j);

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}
