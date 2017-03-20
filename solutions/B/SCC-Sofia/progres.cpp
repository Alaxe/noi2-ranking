#include <iostream>

#define MOD 123456789012345

using namespace std;

int input[1000];
int dp[1000][1000];
int res;

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
        for (int j = 0; j < i; ++j)
        {
            int d = input[i] - input[j];
            if (d > 0)
            {
                dp[i][d] = (dp[i][d] + dp[j][d] + 1) % MOD;
                res = (res + dp[j][d] + 1) % MOD;
                //cout << d << '(' << dp[j][d] << ") : " << input[j] << ' ' << input[i] << '(' << dp[i][d] << ") " << dp[j][d] + 1 << '\n';
            }
        }
        //cout << res << '\n';
    }

    cout << res << '\n';
    return 0;
}
