#include <iostream>
using namespace std;
struct duska
	{
		int x;
		int y;
		int d;
	};
duska k[10001];

int n,t,a[6001],maxy=0,br=0,p;

void init()
	{
		cin>>n;
		for(int i=0;i<n;i++) 
			{
				cin>>k[i].x>>k[i].y>>k[i].d;
				if(k[i].y>maxy) maxy=k[i].y;
			}
		cin>>t;
		for(int i=0;i<t;i++) cin>>a[i]; 
	}
	
int find(int y1,int i)
	{
		int j=0;
		while(j<n)
			{
				if(k[j].y==y1&&a[i]>=k[j].x&&a[i]+1>=k[j].x&&a[i]<=(k[j].x+k[j].d)&&a[i]+1<=(k[j].x+k[j].d)) return j;
				j++;
			}
		return 0;
	}
	
int solve(int i)
	{
		a[i]=p;
		br=0; int y1=maxy;
		int j;
		while(y1>=0)
			{
				int g=find(y1,i);
				if(!g) y1--;
				else
					{
						j=g; a[i]=k[j].x-1; br++; y1--; 	
					}	
			}
		return br;
	}
	
int solve1(int i)
	{
		a[i]=p;
		int br=0; int y1=maxy;
		while(y1>=0)
			{
				int g=find(y1,i);
				if(!g) y1--;
				else
					{
						a[i]=k[g].x+k[g].d; br++; y1--; 	
					}	
			}
		return br;
	}
	
int main()
{
	init();
	for(int i=0;i<t;i++) 
		{
			p=a[i]; cout<<min(solve(i),solve1(i))<<" ";
		}
}

//13 1 4 2 9 5 2 8 1 5 2 2 2 6 2 2 2 6 3 1 3 1 4 3 2 9 3 3 5 4 5 4 5 2 7 5 1 8 6 2 5 2 5 7 8 11
//13 1 4 2 9 5 2 8 1 5 2 2 2 6 2 2 2 6 3 1 3 1 4 3 2 9 3 3 5 4 5 4 5 2 7 5 1 8 6 2 1 5
