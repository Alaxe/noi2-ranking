#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int MAX_N = 128;
const int MOD = 1e9 + 7;
int dp[MAX_N][MAX_N], sz;
string s;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    sz = s.size();
    for(int i = 0; i < sz; ++ i)   dp[i][i] = 1;
    for(int j = 1; j < sz; ++ j)
    {
        for(int i = 0; (i + j) < sz; ++ i)
        {
            if(s[i] != s[i + j])   dp[i][i + j] = ((dp[i][i + j - 1] % MOD) + (dp[i + 1][i + j] % MOD) - (dp[i + 1][i + j - 1] % MOD)) % MOD;
            else   dp[i][i + j] = ((dp[i][i + j - 1] % MOD) + (dp[i + 1][i + j] % MOD) + (1 % MOD)) % MOD;
        }
    }
    cout << dp[0][sz - 1] << "\n";
    return 0;
}