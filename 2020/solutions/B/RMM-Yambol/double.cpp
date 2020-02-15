# include <bits/stdc++.h>
using namespace std;
int dp[205][205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
dp[0][0]=1;
int n,i,j,w1,w2,a,t;
int ans = 0;
cin>>n>>w1>>w2;
for(t=1;t<=n;t++)
{
    cin>>a;
    for(i=w1;i>=0;i--)
    {
        for(j=w2;j>=0;j--)
        {
           if(dp[i][j])continue;
                if(i-a>=0&&dp[i-a][j])
                {
                    dp[i][j]=1;
                    ans=max(ans,i+j);
                  //  cout<<ans<<" "<<i<<" "<<j<<" "<<a<<endl;
                }
                if(j-a>=0&&dp[i][j-a])
                {
                    dp[i][j]=1;
                    ans = max(ans,i+j);
                  //  cout<<ans<<" "<<i<<" "<<j<<" "<<a<<endl;
                }

        }
    }
}
cout<<ans<<endl;
    return 0;
}
