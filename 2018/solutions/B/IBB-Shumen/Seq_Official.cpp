#include <iostream>
using namespace std;
int dp[512][512];
int n,m;
void init()
{
    for(int i=1;i<=300;i++)
    {
        dp[i][1]=1;
        dp[1][i]=1;
    }
}
void inniter(int i,int j)
{
    for(int f=1;f<=j;f++)
    {
        if(i>f)dp[i][j]+=dp[i-f][f];
    }
}
void solve()
{
    for(int i=2;i<=n+2;i++)
    {
        for(int j=2;j<=m+2;j++)
        {
            inniter(i,j);
        }
    }
}
void print()
{
    for(int i=1;i<=n+2;i++)
    {
        for(int j=1;j<=m+2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>n>>m;
    init();
    solve();
    //print();
    cout<<dp[n+1][m]<<endl;
    return 0;
}