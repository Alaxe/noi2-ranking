#include <iostream>
using namespace std;
int main ()
{
	int a,b,n,x[11000],y[11000],w[11000],h[11000],t,c[11000],d[11000],sum[11000];
	cin>>a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>w[i]>>h[i];
	}
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>c[j]>>d[j];
	}
	for(int j=0;j<t;j++)
	for(int i=0;i<n;i++)
	{
		if(d[j]<=x[i]+h[i]&&d[j]>=x[i]) sum[j]=w[i]*h[i];
	}
		for(int j=0;j<t;j++) cout<<sum[j]<<endl;
}
