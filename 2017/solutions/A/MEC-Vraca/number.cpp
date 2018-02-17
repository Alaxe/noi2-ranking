#include<iostream>
#include <math.h>

using namespace std;

int DelitelQ (int x)
{
	int m, y,z, t, p=0;
	m=x;
	if(m%2==0)
	{
		while(m%2==0)
		{
			p++;
			m=m/2;
		}
		t=2*p;
		y=x/t;
		if(t<y==0)
			z=y+1;
		else
			z=y-1;
		if(x==z*y)
			return 1;
	}
	else return 0;
}

int main(){
	int M,N,i, c[100000], br=0;
	int m, y=0,z=0, t=0, p=0, x;
	do {
		cin>>M>>N;
		}
	while(M>N&&M<0&&N<0);
	for(i=M;i<=N;i++)
		c[i]=i;
			
	for(i=M;i<=N;i++)
	{
		if(DelitelQ(c[i])==1)
		br++;
	}
	cout<<br;

	return 0;
	}

