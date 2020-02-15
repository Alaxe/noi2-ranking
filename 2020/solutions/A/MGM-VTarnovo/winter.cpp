#include <iostream>
#include <bitset>
#include <vector>
#include <cstdio>

using namespace std;

int n,m;
int mat[10001][10001];
bitset<10001>used;
bitset<10001>cikal;
bool flag=0;
int curc=-1;
vector<int>path;
void dfs(int node,int par)
{
	path.push_back(node);
	used[node]=1;
	for(int i=1;i<=n;i++)
	{
		if(mat[node][i]>0)
		{
			if(used[i])
			{
				//cout<<"USED:"<<i<<endl;
				if(i!=par&&path.size()>2)
				{
					//cout<<i<<" "<<node<<endl;
					flag=1;	
					curc=i;
				}	
			}
			if(!used[i])
			{
				dfs(i,node);
			}
			
		}
	}
	if(flag)
	{
		bool cc=0;
		for(int i=0;i<path.size();i++)
		{
			//cout<<path[i]<<" ";
			if(path[i]==curc)cc=1;
			if(cc)cikal[path[i]]=1;
		}
		//cout<<endl;
		flag=0;	
	}
	//if(path[path.size()-1]==curc)flag=0;
	path.pop_back();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		mat[a][b]=1;
		mat[b][a]=1;	
	}
	dfs(1,1);
	//cout<<"USED[6]:"<<used[6]<<endl;
	long long br=0;
	//cout<<cikal[7]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(cikal[i])
		{
			br++;
		}
	}
	br=br*(br-1)/2;
	printf("%lld\n",br);
}
/*
7 9
1 2
2 5
2 3
3 4
1 4
3 5
3 6
5 6
6 7
*/

