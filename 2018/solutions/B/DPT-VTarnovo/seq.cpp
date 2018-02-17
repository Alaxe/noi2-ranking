#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int n,m;
long long dp[300][300],s;
void solve()
{
	for(int j=1;j<=n;j++)dp[j][1]=1;
	dp[0][0]=dp[0][1]=1;
	for(int y=0;y<=290;y++)
	{	
		s=0;
		for(int i=0;i<=290;i++)
		{
			if(y>=i && y>=0 && i>=0)s+=dp[y-i][i];
			if(i>1)dp[y][i]+=s;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	solve();
	cout<<dp[n][m]<<endl;
	return 0;
}

