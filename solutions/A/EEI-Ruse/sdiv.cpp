#include<iostream>
using namespace std;
const long long  MAX_N=1000;
const long long  MAX_L=10000;
string s;
long long n;
long long m;
long long dp[MAX_L+100][MAX_N+100];
long long ans;
void input()
{
    cin>>s;
    cin>>n>>m;
}
void output()
{
    cout<<ans<<endl;
}
void solve()
{
    long long cr;
    dp[0][0]=1;
    for (int i=0;i<s.size();++i)
    {
        for (int j=0;j<n;++j)
        {
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=m;
            cr=(j*10+(s[i]-'0'))%n;
            dp[i+1][cr]+=dp[i][j];
            dp[i+1][cr]%=m;
        }
    }
    ans=dp[s.size()][0]-1;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    output();
    return 0;
}