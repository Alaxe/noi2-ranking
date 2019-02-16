#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100000];
int dp2[100000];
int mas[100000];
int liss()
{
	fill(dp,dp+n,1);
	int maxi=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(mas[i]>mas[j])
			{
				dp[i]=dp[j]+1;
			}
		} 
	}
	for(int i=0;i<n;i++)
	{
		if(maxi<dp[i])maxi=dp[i];
	}
	return maxi;
}
int ldss()
{
	int maxi=0;
	fill(dp2,dp2+n,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
				if(mas[i]<mas[j])
				{
					dp[i]=dp[j]+1;
					//break;
				}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(maxi<dp[i])maxi=dp[i];
	}
	return maxi;
}
int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mas[i]);
	}
	//cout<<liss()<<" "<<ldss()<<endl;
	int a=liss(),b=ldss();
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(c<dp[i]+dp2[n-1]-dp2[i])
		{
			c=dp[i]+dp2[n-1]-dp2[i];
		}
	}
	printf("%d\n",max(a,max(b,c)));
	//for(int i=0;)
}
