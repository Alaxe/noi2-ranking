#include <iostream>
#include <stdio.h>
using namespace std;
bool p[100002],po;
int br,a[1002],n,e[1002],s;
void sum()
{
	s=0;po=false;
	for(int g=0;g<n;g++)
	{
		if(a[g]==1)
		{
			po=true;s+=e[g];
		}
	}
	if(p[s]==false && po==true)
	{
		p[s]=true;br++;
	}
}
void re(int l,int r)
{

    a[l]=0;
	if(l==r)
	{
		sum();
		a[l]=1;
		sum();
		return ;
	}
	
	re(l+1,r);
	a[l]=1;
	re(l+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int b=0;b<n;b++)scanf("%d",&e[b]);
    re(0,n-1);
    printf("%d\n",br);
    return 0;
}
