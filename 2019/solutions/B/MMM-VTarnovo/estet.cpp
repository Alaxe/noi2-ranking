#include <iostream>

using namespace std;

int n,dp2[100000],dp[100000],dp1[100000],a[100000];

int bigger(int k)
{
	if(k<=0)return dp1[0];
	for(int i=k-1;i>=0;i--)
		if(a[k]>a[i])dp1[k]=max(dp1[i]+1,dp1[k]);
}

int smaller(int k)
{
	if(k<=0)return dp2[0];
	for(int i=k-1;i>=0;i--)
		if(a[k]<a[i])dp2[k]=max(dp2[i]+1,dp2[k]);
}

int combined(int k,int l)
{
	if(k<=l)return dp[l];
	for(int i=k-1;i>=l;i--)
		if(a[k]<a[i])dp[k]=max(dp[i]+1,dp[k]);	
}

int max3(int x,int y,int z)
{
	int max1;
	max1=max(x,y);
	max1=max(max1,z);
	return max1;
}

int main()
{
	int up,down,updown,max1=0,max2=0,maxcomb=0,maxindex;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	dp1[i]=1;
	dp2[i]=1;
	dp[i]=1;
	}	
	
	for(int i=0;i<n;i++)
	{
	bigger(i);
	smaller(i);
	}
	
	for(int i=0;i<n;i++)
	{
		max2=max(max2,dp2[i]);
		if(max1<dp1[i])
		{
		max1=dp1[i];
		maxindex=i;
		}
	}
	dp[maxindex]=max1;
	for(int i=maxindex+1;i<n;i++)combined(i,maxindex);
	
	for(int i=0;i<n;i++)maxcomb=max(maxcomb,dp[i]);
	cout<<max3(maxcomb,max1,max2);
	
}
