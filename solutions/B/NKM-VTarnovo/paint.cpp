#include <iostream>
using namespace std;
long long M[11001][11001];
int main ()
{
	int height,width,n,t,i,j,k,p,pl=0;
	long long x[11000],y[11000],w[11000],h[11000],a[11000],o[11000];
	cin>>height>>width;
	cin>>n;
	for (i=1;i<=n;i++) cin>>x[i]>>y[i]>>w[i]>>h[i];
	cin>>t;
	for (i=0;i<t;i++) cin>>a[i]>>o[i];
	for (i=0;i<height;i++)
		for (j=0;j<width;j++) M[i][j]=0;
	for (i=1;i<=n;i++)
		for (j=x[i];j<x[i]+w[i];j++)
			for (k=y[i];k<y[i]+h[i];k++) M[k][j]=M[k][j]+i;
	k=0;
	while (k<t)
		{
			p=M[o[k]][a[k]];
			for (i=0;i<width;i++)
				for (j=0;j<height;j++)
					if (M[i][j]==p) pl++;
			cout<<pl<<endl;
			pl=0; k++;
		}
		
}
	
