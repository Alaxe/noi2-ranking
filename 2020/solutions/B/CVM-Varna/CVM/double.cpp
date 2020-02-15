#include<bits/stdc++.h>
using namespace std;
int n,a,b,m[256];
int arr[256];
int dp[256][256];
int bp(int n1,int m1)
{
    if(!n1||!m1) return 0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n1;i++)
    {
        for(int j=1;j<=m1;j++)
        {
            if(i==0&&j>=arr[i]) dp[i][j]=arr[i];
            else if(i&&j>=arr[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
            else if(i) dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n1-1][m1];
}
bool f[256];
int try1()
{
    memcpy(arr,m,sizeof(m));
    int ans=bp(n,a);
    memset(f,0,sizeof(f)); int x=ans;
    for(int i=n-2;i>=0;i--)
    {
        if(dp[i][x]!=dp[i+1][x])
        {
            //cerr<<i<<" "<<x<<" "<<dp[i+1][x]<<endl;
            x-=arr[i+1];
            f[i+1]=1;
        }
    }
    if(x) f[0]=1;
    int n1=0;
    for(int i=0;i<n;i++)
    {
        if(!f[i]) arr[n1++]=m[i];
    }
    //cerr<<n1<<endl;
    return ans+bp(n1,b);
}
int try2()
{
    memcpy(arr,m,sizeof(m));
    int ans=bp(n,b);
    memset(f,0,sizeof(f)); int x=ans;
    for(int i=n-2;i>=0;i--)
    {
        if(dp[i][x]!=dp[i+1][x])
        {
            //cerr<<i<<" "<<x<<" "<<dp[i+1][x]<<endl;
            x-=arr[i+1];
            f[i+1]=1;
        }
    }
    if(x) f[0]=1;
    int n1=0;
    for(int i=0;i<n;i++)
    {
        if(!f[i]) arr[n1++]=m[i];
    }
    //cerr<<n1<<endl;
    return ans+bp(n1,a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) cin>>m[i];
    sort(m,m+n);
    cout<<max(try1(),try2())<<endl;
    return 0;
}
/**

3 10 2
3 4 5

5 10 14
4 5 6 7 8

*/
