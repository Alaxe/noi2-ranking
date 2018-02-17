#include<iostream>
#include<cstdio>
using namespace std;

int n,points,maxpoints;
int x[1002], y[1002];
bool flag=1;

void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
	}
}

void one_line()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			points=2;
			for(int st=0;st<n;st++)
			{
				if((x[st]==x[i] && y[st]==y[i]) || (y[st]==y[j] || x[st]==x[j]))
				{
					flag=0;
				}
				else
				{
					if((x[st]*(y[i]-y[j]) + y[st]*(x[j]-x[i]) + (x[i]*y[j]-x[j]*y[i]))==0)
					{
						points++;
					}
				}
			}
			if(maxpoints<points) maxpoints=points;
		}
	}
	printf("%d\n",maxpoints);
}

int main()
{
	init();
	one_line();
}
