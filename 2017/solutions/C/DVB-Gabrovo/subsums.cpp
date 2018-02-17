#include <iostream>
using namespace std;

const int MAXN = 1 << 10;
const int MAXS = 1 << 11;
const int OVER = 1000000;

int a[MAXN], n;
int dp[MAXN * MAXS];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }

    dp[OVER] = -1;

    for (int i = 1; i <= n; ++ i)
    {
        if (a[i] >= 0)
        {
            for (int j = MAXN * MAXS - 1; j >= a[i]; -- j)
            {
                if (dp[j - a[i]] != 0) dp[j] = 1;
            }
        }
        else
        {
            for (int j = 0; j < MAXN * MAXS + a[i]; ++ j)
            {
                if (dp[j - a[i]] != 0) dp[j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < MAXN * MAXS; ++ i)
    {
        if (dp[i] == 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
