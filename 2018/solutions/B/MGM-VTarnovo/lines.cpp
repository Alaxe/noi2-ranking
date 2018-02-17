#include <bits/stdc++.h>

using namespace std;

struct p
{
	double x,y;
};
int main()
{
	int n;
	cin>>n;
	p ma[n];
	int ans=2;
	int maxi=0;
	for(int i=0;i<n;i++)
	{
		cin>>ma[i].x>>ma[i].y;
	}
	for(int i=0;i<n;i++)
	{	
		for(int j=i+1;j<n;j++)
		{
			for(int h=0;h<n;h++)
			{
				if(h==j||h==i)continue;
				if(ma[i].x==ma[j].x)
				{
					if(ma[h].x==ma[i].x)
					{
					ans++;	
					}
				}
				else if(ma[i].y==ma[j].y)
				{
					if(ma[h].y==ma[i].y)
					{
					ans++;	
					}	
				}
				else
				{
					if((ma[h].x-ma[i].x)/(ma[j].x-ma[i].x)==(ma[h].y-ma[i].y)/(ma[j].y-ma[i].y))
					{
					ans++;	
					}
				}
			}
			if(maxi<ans)maxi=ans;
			ans=2;
		}
	}
	cout<<maxi<<endl;
}
