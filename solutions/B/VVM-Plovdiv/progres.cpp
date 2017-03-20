#include<iostream>
#include<stdio.h>
#define endl '\n'

using namespace std;

long long n, a[1024], dp[1024][1024], mxd=0, ans;
const long long mod=123456789012345ll;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i][a[i]-a[j]] += (dp[j][a[i]-a[j]]+1)%mod;
                mxd=max(mxd,a[i]-a[j]);
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=mxd;j++)
        {
            ans=(ans+dp[i][j])%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
