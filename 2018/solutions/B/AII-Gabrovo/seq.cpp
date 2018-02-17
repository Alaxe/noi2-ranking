# include<iostream>
using namespace std;

long long dp[272][272];
int n,m;

long long solve(int sum, int last)
{
    if(dp[sum][last]) return dp[sum][last];
    if(sum==n) return 1;

    long long ans=0;
    for(int i=last; i>0; i--)
    {
        if(sum+i<=n)
            ans=ans+(long long)solve(sum+i,i);
    }
    return dp[sum][last]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cout<<solve(0,min(m,n))<<endl;
}
