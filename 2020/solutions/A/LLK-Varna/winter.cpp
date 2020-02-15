#include<iostream>
#include<cstring>
#include<vector>
#define MAX 100001
using namespace std;
int n,m,br;
vector<int> V[MAX];
int used[MAX];
int first[MAX];
int street[1001][1001];
int blocked[1001][1001];
long long ans=0;
bool flag=false;
struct str
{
	int x,y;
};
str st[MAX*2];
void dfs(int i, int x, int y)
{
	if(i==y)
	{
		flag=true;
		return;
	}
	if(flag)
		return;
	used[i]=1;
	for(int a=0; a<V[i].size(); a++)
	{
        int d=V[i][a];
        if(!used[d] && !street[i][d])
		{
			dfs(d,x,y);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for(int a=0; a<m; a++)
	{
		int x,y;
		cin>>x>>y;
		V[x].push_back(y);
		V[y].push_back(x);
		st[a].x=x;
		st[a].y=y;
	}
	ans=n*(n-1)/2;
	for(int a=0; a<m; a++)
	{
		int x=st[a].x;
		int y=st[a].y;
		street[x][y]=1;
		street[y][x]=1;
		for(int b=1; b<n; b++)
		{
			for(int c=b+1; c<=n; c++)
			{
                flag=false;
                memset(used,0,sizeof(used));
                dfs(b,b,c);
                if(flag==false)
				{

					if(!blocked[b][c])
					{
						ans--;
						blocked[b][c]=1;
						blocked[c][b]=1;
					}
				}
			}
		}
		street[x][y]=0;
		street[y][x]=0;
	}
	cout<<ans<<endl;
	return 0;
}
/**
11 13
1 2
1 4
1 9
1 10
2 3
3 4
3 5
4 5
6 7
6 8
7 8
7 10
10 11


5 5
1 2
2 3
3 1
2 4
2 5
*/
