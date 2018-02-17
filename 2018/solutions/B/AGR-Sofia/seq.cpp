#include<iostream>
using namespace std;
long long n, m;
long long dp[300][300];
long long calc (long long a, long long b)
{
    if(a == 0 || b == 1)
    {
        dp[a][b] = 1;
        return 1;
    }
    if(dp[a][b] != 0)   return dp[a][b];
    for(long long i = 0; i * b <= a; i ++)
    {
        dp[a][b] += calc(a - i * b, b - 1);
    }
    return dp[a][b];
}
int main()
{
    cin >> n >> m;
    cout << calc(n, m);
}
