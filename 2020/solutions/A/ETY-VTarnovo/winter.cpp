#include <iostream>
#include<vector>
using namespace std;

int n,m;
int used[100002],ver[100002];
vector<int> gr[100002];
vector<int> ans;
int c=0,dc=0;

void dfs(int node,int par)
{	
	used[node]=1;
	c++; 
	ver[node]=c;
	for(int i=0;i<gr[node].size();i++)
	{
		if(used[gr[node][i]]==0)
		{
			dfs(gr[node][i],node);
		}
		else if(used[gr[node][i]]==1 && gr[node][i]!=par)
		{
			dc=max(c,dc);
		}
	}
	
	if(dc>2) ans.push_back(dc);
	c=dc=0;
}


void init()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1,1);
	long long sum=0;
	for(int i=0;i<ans.size();i++) 
	{
		sum+=ans[i]*(ans[i]-1)/2;
	}
	printf("%lld\n",sum);
}

int main()
{
	init();
}

/*
5 5
1 2
2 3
3 1
2 4
2 5

11 13
1 2
1 3
2 4
3 4
4 5
5 6
6 11
5 7
7 8
7 9
8 9
9 10
8 10

11 14
1 2
1 3
2 4
3 4
4 5
5 6
6 11
5 7
7 8
7 9
8 9
9 10
8 10
3 8
*/
