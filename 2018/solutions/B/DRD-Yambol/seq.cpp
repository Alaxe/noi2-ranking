#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long Int;

const int N=275;

Int dp[N][N][N];
int n,m;

Int Solve(int ind,int last,int sum)
{
 int i;

  if(sum>n)
   return 0;

  if(sum==n)
   return 1;

  if(dp[ind][last][sum]!=0)
   return dp[ind][last][sum];

  for(i=last;i>=1;i--)
   dp[ind][last][sum]+=Solve(ind+1,i,sum+i);

 return dp[ind][last][sum];
}

int main()
{

Int ans;

scanf("%d%d",&n,&m);

m=min(n,m);

ans=Solve(0,m,0);

printf("%lld\n",ans);

return 0;
}
