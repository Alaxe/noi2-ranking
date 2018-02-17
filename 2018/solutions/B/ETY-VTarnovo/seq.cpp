#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
long long dp[271][271];

void dp_fill()
{
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
		for(int j=1;j<i;j++)
		{
			for(int st=1;st<=j;st++)
			{
				dp[i][j]=dp[i][j]+dp[i-j][st];
			}
		}
	}
}

void get_ans()
{
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		ans=ans+dp[n][i];
	}
	cout<<ans<<endl;
}

int main()
{
	dp_fill();
	get_ans();
}
