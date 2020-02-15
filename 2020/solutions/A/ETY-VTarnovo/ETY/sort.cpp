#include <iostream>
#include<cstdio>
using namespace std;

int n,dp[10000][1003];
int a[1005];

int abs(int a,int b)
{
	if(a-b<0) return b-a;
	return a-b;
}

void solve()
{
	scanf("%d",&n);
	int minn,maxn;
	scanf("%d",&a[0]);
	minn=maxn=a[0];
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	
	for(int i=0;i<=(maxn-minn);i++)
	{
		dp[0][i]=abs(a[0],i+minn);
	}
	
	int curmin;
	for(int i=1;i<n;i++)
	{
		curmin=maxn;
		for(int j=0;j<=(maxn-minn);j++)
		{
			curmin=min(curmin,dp[i-1][j]);
			dp[i][j]=curmin+abs(a[i],j+minn);
		}
	}
	
	int ans=dp[n-1][0];
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<=maxn-minn;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	for(int i=1;i<=(maxn-minn);i++) ans=min(ans,dp[n-1][i]);
	printf("%d\n",ans);
}

int main()
{
	solve();
}

/*
5
2 6 4 3 2

5
2 6 6 7 7
*/
