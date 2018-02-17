#include<bits/stdc++.h>
using namespace std;
long long dp[128][128],mod=1000000007ll;
string s;
long long f(int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return dp[l][r]=1;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(s[l]==s[r])
        dp[l][r]=(f(l+1,r)+f(l,r-1)+1)%mod;
    else
        dp[l][r]=(f(l+1,r)+f(l,r-1)-f(l+1,r-1))%mod;
    return dp[l][r];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>s;
    cout<<f(0,s.size()-1)<<endl;
    return 0;
}
