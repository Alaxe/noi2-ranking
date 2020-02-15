#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll n,w1,w2,a[256],i,dp[256][256][256],j,l,ans=-1;
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n>>w1>>w2;
for(i=0;i<n;i++)cin>>a[i];
memset(dp,-1,sizeof(dp));
for(i=0;i<n;i++)dp[i][w1][w2]=1;
dp[0][w1-a[0]][w2]=1;
dp[0][w1][w2-a[0]]=1;
for(i=1;i<n;i++)
{
    for(j=0;j<=w1;j++)
        for(l=0;l<=w2;l++)dp[i][j][l]=dp[i-1][j][l];
for(j=0;j<=w1-a[i];j++)
    for(l=0;l<=w2;l++)if(dp[i-1][j+a[i]][l]==1)dp[i][j][l]=1;
for(j=0;j<=w2-a[i];j++)
    for(l=0;l<=w1;l++)if(dp[i-1][l][j+a[i]]==1)dp[i][l][j]=1;
}
for(i=0;i<=w1;i++)
    {for(j=0;j<=w2;j++)if(dp[n-1][i][j]==1)ans=max(ans,(w1+w2-i-j));
    //cout<<dp[n-1][i][j]<<" ";
    //cout<<endl;
    }
    cout<<ans<<endl;
return 0;
}


    /*for(j=0;j<=w1-a[i];j++)
        for(l=0;l<=w2;l++){if((dp[i-1][0][j+a[i]][l]!=(-1))||(dp[i-1][1][j+a[i]][l]!=(-1))||(dp[i-1][2][j+a[i]][l]!=(-1)))dp[i][1][j][l]+=a[i];
        else dp[i][1][j][l]=-1;
        }
          for(j=0;j<=w2-a[i];j++)
        for(l=0;l<=w1;l++){if((dp[i-1][0][l][j+a[i]]!=(-1))||(dp[i-1][1][l][j+a[i]]!=(-1))||(dp[i-1][2][l][j+a[i]]!=(-1)))dp[i][2][l][j]+=a[i];
        else dp[i][2][l][j]=-1;
        }
        for(j=0;j<=w1;j++)
            for(l=0;l<=w2;l++)dp[i][0][j][l]=max(max(dp[i-1][1][j][l],dp[i-1][0][j][l]),dp[i-1][2][j][l]);*/
