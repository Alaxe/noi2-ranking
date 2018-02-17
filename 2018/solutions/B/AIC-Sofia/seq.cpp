#include <iostream>

using namespace std;

unsigned long long dp [270][270];

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio (false);
    int n, m;
    cin >> m >> n;
    for (int sum = 0 ; sum <= m ; sum ++)
        for (int prev = 1 ; prev <= n ; prev ++)
            if (sum == 0)
                dp [sum][prev] = 1;
            else
                for (int i = 1 ; i <= min (sum, prev) ; i ++)
                    dp [sum][prev] += dp [sum - i][i];
    cout << dp [m][n] << endl;
    return 0;
}
