#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long dp[1024][1024];
long long a[1024],n,mod=123456789012345ll;
vector<long long>p[4096];
long long d,start;
long long ans;
long long f(long long pos)
{
    if(pos==n-1)
        return (start!=pos);
    if(dp[pos][d]!=-1)
        return dp[pos][d];
    long long now=a[pos]+d;
    if(p[now].size()==0)
        return (pos!=start);
    long long l=0,r=p[now].size()-1,i=1024;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(p[now][mid]>pos)
        {
            i=min(i,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    if(i==1024)
        return (pos!=start);
    dp[pos][d]=(pos!=start);
    for(;i<p[now].size();i++)
        dp[pos][d]=(dp[pos][d]+f(p[now][i]))%mod;
    return dp[pos][d];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld",&n);
    long long minn=1024,maxx=-1;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
        p[a[i]].push_back(i);
    }
    for(d=1;d<=maxx-minn;d++)
    {
        for(start=0;start<n;start++)
        {
            if(dp[start][d]>0)
                ans--;
            ans=(ans+f(start))%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
