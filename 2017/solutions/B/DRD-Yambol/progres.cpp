#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1005];
long long dp[1005][1005];
long long mod=123456789012345;

int main()
{

int n,i,j,d;
long long ans;

scanf("%d",&n);

 for(i=1;i<=n;i++)
  scanf("%d",&a[i]);

memset(dp,0,sizeof(dp));

 for(i=2;i<=n;i++)
  for(j=i-1;j>=1;j--)
  {
   if(a[i]>a[j])
   {
    d=a[i]-a[j];
    dp[i][d]=(dp[i][d]+dp[j][d]+1)%mod;
   }
  }

ans=0;
 for(i=2;i<=n;i++)
  for(j=1;j<=1000;j++)
   ans=(ans+dp[i][j])%mod;

printf("%lld\n",ans);

return 0;
}
