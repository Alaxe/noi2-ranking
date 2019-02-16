#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>gr[200001];
int gn,dn;
bool used[200001];
int mapos=0;
void paralobh(pair<int,int>mesta,int pos)
{
	used[mesta.first]=1;
	used[mesta.second]=1;
	if(pos>mapos)mapos=pos;
	int gla;
	if(gr[mesta.first].size()<gr[mesta.second].size())
	{
			gla=mesta.first;
	}	
	else
	{
		gla=mesta.second;
	}
	vector<int>que;
	for(int i=0;i<gr[gla].size();i++)
	{
		if(!used[gr[gla][i]])
		{
			que.push_back(gr[gla][i]);
		}
	}
	int vt=mesta.first+mesta.second-gla;
	for(int i=0;i<gr[vt].size();i++)
	{
		if(!used[gr[vt][i]])
		{
			for(int j=0;j<que.size();j++)
			{
				if(que[j]!=gr[vt][i])
				{
				paralobh(make_pair(que[j],gr[vt][i]),pos+1);	
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	scanf("%d %d",&gn,&dn);
	used[gn]=1;
	used[dn]=1;
	paralobh(make_pair(gn,dn),1);
	printf("%d\n",mapos);
	return 0;
}
