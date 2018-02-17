#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int dp[10005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, sz, i, j;
    bool ks=0;
    string s;
    cin>>s;
    sz=s.size();
    int a[sz+1];
    for(i=1;i<=sz;i++)
    {
        a[i]=s[i-1]-'0';
    }
    cin>>n>>m;
    for(i=1;i<=sz;i++)
    {
        dp[i][a[i]%n]=1;
    }
    for(i=1;i<=sz;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]%=m;
            dp[i+1][j]+=dp[i][j];
            dp[i+1][(j*10+a[i+1])%n]+=dp[i][j];
        }
    }
    cout<<dp[sz][0]<<"\n";
    return 0;
}
