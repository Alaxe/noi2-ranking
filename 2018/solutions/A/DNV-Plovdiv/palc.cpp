#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
string s;
int n;
long long dp[128][128],ans;
long long Mod(long long x)
{
    while(x>=MOD)
    {
        x-=MOD;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
            {
                dp[i][j]=1;
                for(int p=0;p<i;p++)
                {
                    for(int t=j+1;t<n;t++)
                    {
                        if(s[p]==s[t])
                        {
                            dp[i][j]+=dp[p][t];
                            dp[i][j]=Mod(dp[i][j]);
                        }
                    }
                }
                ans+=dp[i][j];
                ans=Mod(ans);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int p=0;p<i;p++)
        {
            for(int t=i+1;t<n;t++)
            {
                if(s[p]==s[t])
                {
                    ans+=dp[p][t];
                    ans=Mod(ans);
                }
            }
        }
    }
    ans+=n;
    ans=Mod(ans);

    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans<<endl;

    return 0;
}
