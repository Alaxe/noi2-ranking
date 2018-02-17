#include <bits/stdc++.h>

using namespace std;

long long mat[271][271];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int temp=0;
	mat[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int h=j;h>=0;h--)
			{
			mat[i][j]+=mat[i-j][h];	
			}		
		}
	}
	long long ans=0;
	for(int j=m;j>=0;j--)
	{
	ans+=mat[n][j];		
	}
	printf("%lld\n",ans);
}
