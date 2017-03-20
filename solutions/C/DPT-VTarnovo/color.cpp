#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int t,n,y;
	scanf("%d",&t);
	int a[t];
	for(int iu=0;iu<t;iu++)
	{
		int n,br=1;
		scanf("%d",&n);
		vector<pair<int,int> >g[n+1];
		for(int m=1;m<n+1;m++)
		{
			scanf("%d",&y);
			bool lp[100002];
			for(int z=0;z<n+3;z++)lp[z]=true;
			for(int az=0;az<g[y].size();az++)
			{
				lp[g[y][az].second]=false;
				
			}
			for(int az=0;az<g[m].size();az++)
			{
				lp[g[m][az].second]=false;
			
			}
			int oi=1;
			while(lp[oi]!=true)oi++;
			
			g[m].push_back(make_pair(y,oi));
			g[y].push_back(make_pair(m,oi));
			if(br<oi)br=oi;
		}
		a[iu]=br;
	}
	for(int h=0;h<t;h++)printf("%d\n",a[h]);
    return 0;
}
