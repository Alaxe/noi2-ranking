#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAX_N = 1e3 + 24;
long long dp[2][MAX_N], M;
int N;
string s;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> N >> M;
    int sz = s.size();
    dp[0][0] = 1;
    int sq = 0;
    for(int i = 0; i < sz; ++ i)
    {
        sq ^= 1;
        memset(dp[sq], 0, sizeof(dp[sq]));
        for(int j = 0; j < N; ++ j)
        {
            dp[sq][j] += dp[sq ^ 1][j];
            dp[sq][j] %= M;
            dp[sq][(j * 10 + (s[i] - '0')) % N] += dp[sq ^ 1][j];
            dp[sq][(j * 10 + (s[i] - '0')) % N] %= M;
        }
    }
    if(dp[sq][0] > 0)   cout << dp[sq][0] - 1 << "\n";
    else   cout << M - 1 << "\n";
    return 0;
}