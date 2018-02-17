#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e3+5;
const long long mod=123456789012345;
long long br[N][N];
long long dp[N][N];
long long n;
long long a[N];
long long ans;
int main()
{
    long long i,j;
    cin>>n;
    for(i=1;i<=n;i++)
     scanf("%lld",&a[i]);
    for(i=1;i<=1000;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[j]==i)
             br[i][j]=br[i][j-1]+1;
            else
             br[i][j]=br[i][j-1];
        }
    }
    for(i=1;i<=1000;i++) // the d we are making sequences with
    {

        for(j=n;j>=1;j--)
        {
            if(a[j]+i>1000)
             continue;

            dp[i][a[j]]=(dp[i][a[j]]+br[a[j]+i][n]-br[a[j]+i][j])%mod;

            dp[i][a[j]]=(dp[i][a[j]]+dp[i][a[j]+i])%mod;
        }
    }
    for(i=1;i<1000;i++)
     for(j=1;j<=1000;j++)
     {
        ans+=dp[i][j];
        ans=ans%mod;
     }
    cout<<ans<<endl;
    return 0;
}
