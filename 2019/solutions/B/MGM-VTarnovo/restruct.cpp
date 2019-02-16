#include <bits/stdc++.h>

using namespace std;

vector<int>gr[5001];
int n,k;
bool used[5001];
long long zaplata[5001];
int root[5001];
void dfs(int start)
{
	used[start]=1;
	bool flag=false;
	for(int i=0;i<gr[start].size();i++)
	{
		if(!root[gr[start][i]])
		{
		root[gr[start][i]]=start;	
		}
	}
	for(int i=0;i<gr[start].size();i++)
	{
		if(!used[gr[start][i]]&&root[gr[start][i]]==start)
		{
			dfs(gr[start][i]);
			flag=true;
		}
	}
	if(flag==false)
	{
		zaplata[start]=k;
	}
	else
	{
		for(int i=0;i<gr[start].size();i++)
		{
			if(root[gr[start][i]]==start)zaplata[start]+=zaplata[gr[start][i]];	
		}
		zaplata[start]+=k;
		
	}
}
int main()
{	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int br;
		cin>>br;
		for(int j=0;j<br;j++)
		{
			int a;
			cin>>a;
			gr[a].push_back(i);
		}
	}
	int maxi=0;
	int gn;
	for(int i=1;i<=n;i++)
	{
		if(gr[i].size()>maxi)
		{
			maxi=gr[i].size();
			gn=i;
		}
	}
	dfs(gn);
	long long suma=0;
	for(int i=1;i<=n;i++)
	{
		suma+=zaplata[i];
	}
	cout<<suma<<endl;
}
/*
4 100
1 4
3 1 3 4
2 1 2
1 3
*/
