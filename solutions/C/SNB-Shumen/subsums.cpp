#include<iostream>
#include<algorithm>
using namespace std;
long long const MAXN=1000005,maxx=1<<21;
long long dp[maxx*2],maxt;
int main()
{
    long long n,i,j,br=0;
    int x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x<0)
        for(j=max(0,x);j<maxx;j++)
        {
            dp[j]=max(dp[j],dp[j-x]);
        }
        if(x>0)
        {
            maxt=max(x,0);
            for(j=maxx-1;j>=maxt;j--)
            {
                dp[j]=max(dp[j],dp[j-x]);
            }
        }
        dp[x+MAXN]=1;
    }
    for(i=0;i<maxx;i++)
    {
        br+=dp[i];
    }
    cout<<br<<endl;
    return 0;
}
