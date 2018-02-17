#include <iostream>
using namespace std;
int main()
{
	long long n,q,i,m[10009],br=0,l=0;
	cin>>n;
	cin>>m[0];

	for(i=1;i<n;i++)
	{
		cin>>m[i];
		l=max(l,m[i]);

	}
	if(n>1)
	{
		for(i=0;i<n;i++)
	{
		br=l-m[i]+br;
	}
	}

	cin>>q;

	cout<<br*q<<endl;

	return 0;
}
