#include<iostream>
using namespace std;
long long dp[64][64];
int k,m,n;
int main()
{
    cin>>k>>m>>n;
    for(int i=1;i<m;i++)
        dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(j+k<m)dp[i][j]+=dp[i-1][j+k];
            if(j-k>0)dp[i][j]+=dp[i-1][j-k];
        }
    }
    long long ans=0;
    for(int i=1;i<m;i++)
        ans+=dp[n][i];
    cout<<ans<<endl;
    return 0;
}

