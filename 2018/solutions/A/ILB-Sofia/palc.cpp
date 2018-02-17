#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>
#define X first
#define Y second

#define _ << " " <<
#define debug(x) #x << " = " << x

#define ll long long
#define ull unsigned long long

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const int mod = 1000000007;

const int maxn = 128;
ll dp[maxn][maxn];

int main()
{
    std::ios::sync_with_stdio(false);

    std::string in;
    std::cin >> in;

    int n = in.length();
    for (int d = 0; d < n; d++)
    {

        for (int i = 0; i + d < n; i++)
        {
            const int j = i + d;
            if (i == j)
            {
                dp[i][j] = 1;

      //      std::cout << debug(i) _ debug(j) _ debug(dp[i][j]) << std::endl;

                continue;
            }

            if (i == j - 1)
            {
                dp[i][j] = 2;
                if (in[i] == in[j]) dp[i][j] = 3;

       //     std::cout << debug(i) _ debug(j) _ debug(dp[i][j]) << std::endl;

                continue;
            }

            for (int k = j; k > i + 1; k--)
            {
                if (in[i] == in[k])
                    dp[i][j] += dp[i + 1][k - 1] + 1;
            }

            if (in[i] == in[i + 1])
                dp[i][j]++;

            for (int k = i + 1; k < j - 1; k++)
            {
                if (in[k] == in[j])
                    dp[i][j] += dp[k + 1][j - 1] + 1;
            }
            if (in[j - 1] == in[j])
                dp[i][j]++;

            dp[i][j] += dp[i + 1][j - 1];
            dp[i][j] += 2;
            dp[i][j] %= mod;

        //    std::cout << debug(i) _ debug(j) _ debug(dp[i][j]) << std::endl;
        }
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}
