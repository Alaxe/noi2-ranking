#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std; 

int n;
int minimuma(vector<int>a)
{
	int curm=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(curm>a[i])
		{
			curm=a[i];
		}
	}
	return curm;
}
int maximuma(vector<int>a)
{
	int curm=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(curm<a[i])
		{
			curm=a[i];
		}
	}
	return curm;
}
long long solve(vector<int>a) 
{ 
    int mini = minimuma(a); 
    int maxi = maximuma(a); 
    long long dp[n][maxi + 1]; 
    for (int i=mini;i<=maxi;i++) 
	{ 
        dp[0][i] = abs(a[0]-i); 
    } 
    for (int i=1;i<n;i++) 
	{ 
        long long tmp=LONG_LONG_MAX; 
        for (int j=mini;j<=maxi;j++) 
		{ 
            tmp=min(tmp,dp[i-1][j]); 
            dp[i][j]=tmp+abs(a[i]-j); 
        } 
    }
    long long ans=LONG_LONG_MAX; 
    for (int j=mini;j<=maxi;j++) 
	{ 
        ans=min(ans,dp[n-1][j]); 
    } 
    return ans; 
} 
int main() 
{ 
    vector<int>mas;
    scanf("%d",&n);
    int a;
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a);
    	mas.push_back(a);
	}
	printf("%lld\n",solve(mas));
    return 0; 
} 
