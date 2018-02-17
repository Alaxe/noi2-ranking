#include<iostream>
using namespace std;
long long MOD = 519;
int main()
{
    string a;
    cin>>a;
    int s = a.length();
    long long dp[s][s];
    for(int i = 0;i < s;i++)
        for(int j = 0;j < s;j++)
            dp[i][j] = 0;
    for(int i =0;i < s;i++)
        dp[i][i] = 1;
    for(int len = 2; len<=s;len++)
    {
        for(int i = 0;i < s;i++)
        {
            int k = len+i-1;
            if(k>=s)
                break;
            if(a[i] == a[k])
                dp[i][k] = dp[i+1][k] + dp[i][k-1]+1;
            else
                dp[i][k] = dp[i][k-1] + dp[i+1][k] - dp[i+1][k-1];
        }
    }
    cout<<dp[0][s-1]%MOD;
    return 0;
}
