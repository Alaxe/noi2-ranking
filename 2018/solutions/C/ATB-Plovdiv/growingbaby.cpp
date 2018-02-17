#include<bits/stdc++.h>
using namespace std;
long long ans=0,k=1,i,n,m,p,q,dp[12000][4];
int main()
{cin>>m>>n>>p>>q;
memset(dp,0,sizeof(dp));
for(i=1;i<=30;i++)k*=2;
dp[m][0]=1;
for(i=m;i<n+p;i++)
{if(dp[i-p][0]>0){dp[i][0]=(dp[i-p][0]+dp[i][0])-(dp[i-p][0]+dp[i][0])/k*k;
if(i<n)dp[i-q][1]=(dp[i-p][0]+dp[i-q][1])-(dp[i-p][0]+dp[i-q][1])/k*k;
}
if(dp[i-p][1]>0){dp[i][0]=(dp[i-p][1]+dp[i][0])-(dp[i-p][1]+dp[i][0])/k*k;
if(i<n)dp[i-q][1]=(dp[i-p][1]+dp[i-q][1])-(dp[i-p][1]+dp[i-q][1])/k*k;}
}
for(i=n;i<n+p;i++)ans=(ans+dp[i][0])-(ans+dp[i][0])/k*k;
cout<<ans<<endl;
return 0;
}
