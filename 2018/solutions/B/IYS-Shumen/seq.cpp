#include <bits/stdc++.h>
using namespace std;
long long dp[273][273];
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j,l;
    for(i=1;i<=270+1;i++)
    {
        dp[0][i]=1;
        dp[i][0]=1;
        dp[1][i]=1;
        dp[i][1]=1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if(i<j)dp[i][j]=dp[i][j-1];
            else 
            for(l=1;l<=j;l++)
            dp[i][j]+=dp[i-l][l];
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }*/
    cout<<dp[n][m]<<endl;
    return 0;
}