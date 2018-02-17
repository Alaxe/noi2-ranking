#include<iostream>
#include<algorithm>
using namespace std;
long long dp[275][275];
void set_base(int n)
{
    int i;
    for(i=1;i<=n+1;i++)
    {
        dp[1][i]=1;
        dp[i][1]=1;
    }
}
int main()
{
    int n,m,i,j,p;
    cin>>n>>m;
    set_base(n);
    for(i=2;i<=n+1;i++)
        for(j=2;j<=n+1;j++)
            for(p=1;p<=j;p++)
                if(i>p)dp[i][j]+=dp[i-p][p];
    if(m>n)m=n;
    cout<<dp[n+1][m]<<endl;
	return 0;
}
