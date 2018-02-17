#include <bits/stdc++.h>
using namespace std;
const long long mod=(1<<30);
long long dp[10000], dp1[10000][2];
long long m, n, p, q, t=0, r=0;
bool fl=0;
/*long long rec(long long int teglo)
{
    //if (teglo>t && fl==0) fl=1;
    //if (teglo>t && fl==1) {fl=0;return 0;}
    if (teglo==0) return 1;
    if (teglo<0) return 0;
    if (dp[teglo]!=-1)
        return dp[teglo];
    dp[teglo]=(rec(teglo-p)%mod+rec(teglo-p+q)%mod)%mod;

    cout<<dp[teglo]<<" "<<teglo<<endl;
    return dp[teglo]%mod;
}*/
int main()
{

    cin>>m>>n>>p>>q;
    t=n-m;
    r=p-q;
    for (int i=0; i<t+100; i++) dp[i]=-1;

    long long sum=0;
  /*  for (int i=t; i<t+p; i++)
    {
        //fl=0;
        sum=( sum%mod+rec(i)%mod)%mod;
    }cout<<sum<<endl;*/
    dp1[0][0]=1;
    for (int i=0; i<t+p; i++)
    {
        if (dp1[i-p][0]>0)
        {
            dp1[i][0]=((dp1[i-p][0])%mod+(dp1[i][0])%mod)%mod;
            if (i<t) dp1[i-q][1]=(dp1[i-p][0]%mod+dp1[i-q][1]%mod)%mod;
        }
        if (dp1[i-p][1]>0)
        {
            dp1[i][0]=(dp1[i-p][1]%mod+dp1[i][0]%mod)%mod;
            if (i<t) dp1[i-q][1]=(dp1[i-p][1]%mod+dp1[i-q][1]%mod)%mod;
        }
    }
    for (int i=t; i<p+t; i++) sum=(sum%mod+dp1[i][0]%mod)%mod;
    cout<<sum%mod<<endl;
    return 0;
}
