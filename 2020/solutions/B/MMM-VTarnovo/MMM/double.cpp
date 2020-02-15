#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n,W1,W2,maxsum=INT_MIN,a[200];
bool dp[210][210][210];
void C(int index,int w1,int w2)
{	
	if(dp[index][w1][w2])return;
	if(w1>W1||w2>W2)return;
	maxsum=max(maxsum,w1+w2);
	if(index==n)return;
	C(index+1,w1,w2);
	C(index+1,w1+a[index],w2);
	C(index+1,w1,w2+a[index]);
	dp[index][w1][w2]=true;
}

int main()
{
	cin>>n>>W1>>W2;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[i][j][k]=false;
	for(int i=0;i<n;i++)cin>>a[i];
	C(0,0,0);
	swap(W1,W2);
	C(0,0,0);
	cout<<maxsum<<endl;	
}

