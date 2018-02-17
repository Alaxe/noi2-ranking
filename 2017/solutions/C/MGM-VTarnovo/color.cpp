#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
	int N;
	int t;
	vector<int>ss[100000];
	bool is=false;
	int x[100000];
	scanf("%d",&t);
	int tr[t];
	int m=0;
	for(int i=0;i<t;i++)
	{
	scanf("%d",&N);
	for(int j=0;j<N;j++)
	{
		scanf("%d",&x[j]);
		for(int h=0;h<ss[j].size();h++)
		{
			if(ss[j][h]==x[j])
			{
				is=true;
				break;
			}
		}
		if(is==false)
		{
		ss[x[j]-1].push_back(j+1);
		ss[j].push_back(x[j]);	
		}
		is=false;	
	}
	for(int j=0;j<N;j++)
	{
		if(m<ss[j].size())
		{
			m=ss[j].size();
		}
	}
	tr[i]=m;
	m=0;
	}
	for(int i=0;i<t;i++)
	{
		printf("%d\n",tr[i]);
	}
	
}
