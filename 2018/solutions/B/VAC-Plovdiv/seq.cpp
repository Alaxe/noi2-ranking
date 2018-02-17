#include<bits/stdc++.h>
using namespace std;

long long dp[300][300]; //suma, max

long long summ(long long a, long long b) {return a+b;}

void mainp()
{
    int n, m;
    cin>>n>>m;

    dp[0][0]=1;
    long long ans=0;

    for(int sum=1; sum<=n; sum++)
        for(int temp=1; temp<=m&&temp<=sum; temp++)
            for(int maxx=0; maxx<=m&&maxx<=temp; maxx++)
                dp[sum][temp]=summ(dp[sum-temp][maxx], dp[sum][temp]);

    for(int temp=1; temp<=m&&temp<=n; temp++) ans=summ(ans, dp[n][temp]);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mainp();
    return 0;
}
