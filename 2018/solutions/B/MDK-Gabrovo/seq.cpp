#include<bits/stdc++.h>
using namespace std;
const int nmax=275;
long long dp[nmax][nmax];

int main()
{
    dp[0][0]=1;
    int n,m;
    cin>>n>>m;
    m=min(n,m);
    for(int sum=1;sum<=n;sum++)
        for(int last=1;last<=m&&last<=sum;last++)
        {
        dp[sum][last]=dp[sum][last-1]+dp[sum-last][min(last,sum-last)];
        //if(dp[sum][last]<dp[sum][last-1]||dp[sum][last]<dp[sum-last][min(last,sum-last)])cout<<"NO"<<endl;
        }
    cout<<dp[n][m]<<endl;
    return 0;
}
