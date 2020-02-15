#include <bits/stdc++.h>
#define MAXN 203
#define endl '\n'

using namespace std;

int n, w1, w2;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN];
bool calc[MAXN][MAXN][MAXN];

void input()
{
    cin >> n >> w1 >> w2;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
}


void solve()
{
    for (int i = 0; i <= n; ++i)
        dp[0][0][i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= w1; ++j)
        {
            for (int k = 0; k <= w2; ++k)
            {
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= arr[i])
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-arr[i]][k] + arr[i]);
                if (k >= arr[i])
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-arr[i]] + arr[i]);
            }
        }
    }

    cout << dp[n][w1][w2] << endl;
}

/**

3 10 2
3 4 5

5 10 14
4 5 6 7 8

6 7 8
3 4 4 5 1 1


*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();


    return 0;
}
