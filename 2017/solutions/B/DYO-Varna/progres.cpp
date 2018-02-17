#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define NMax 1000
#define MaxValue 1000

long long n,arr[NMax+5],ans,dmax,maxn,minn=MaxValue+5;
long long dp[NMax+5][NMax+5],cnt[NMax+5][NMax+5];
long long ima[NMax+5];

const long long MOD=123456789012345LL;

int main()
{
    scanf("%lld",&n);

    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]>maxn)maxn=arr[i];
        if(arr[i]<minn)minn=arr[i];
    }

    for(long long i=0;i<MaxValue+5;i++)
        ima[i]=0;

    dmax=maxn-minn;

    ima[arr[0]]=1;

    for(long long i=1;i<n;i++)
    {
        ima[arr[i]]++;
        ima[arr[i]]%=MOD;
        for(long long j=1;j<=dmax;j++)
        {
            if(arr[i]<j||ima[arr[i]-j]==0)continue;

            dp[i][j]=(cnt[arr[i]-j][j]+ima[arr[i]-j])%MOD;
            cnt[arr[i]][j]+=dp[i][j];
            cnt[arr[i]][j]%=MOD;

            ans+=dp[i][j];
            ans%=MOD;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
