#include<bits/stdc++.h>
#define MAXN 1024
#define MOD 123456789012345LL
using namespace std;
long long arr[MAXN],n,maxx;
long long ans,dp[MAXN][MAXN];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(maxx<arr[i])maxx=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<maxx;j++)
        {
            dp[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]-arr[j]>0)
            {
                dp[i][arr[i]-arr[j]]=(dp[i][arr[i]-arr[j]]+dp[j][arr[i]-arr[j]])%MOD;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<maxx;j++)
        {
            ans=(ans+dp[i][j]-1)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}


/*
3
1 2 3

6
1 9 1 9 2 3
*/
