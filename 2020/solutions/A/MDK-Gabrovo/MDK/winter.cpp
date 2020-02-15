#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector< pair<int/*to*/,int/*id*/> > adj[nmax];

int in[nmax],low[nmax];
bool been[nmax];
int t;

bool cut[nmax];
void dfs(int node,int parent)
{
    if(been[node])return;
    been[node]=1;
    t++;
    in[node]=t;
    low[node]=t;
    for(auto k:adj[node])
        if(k.first!=parent)
        {
            dfs(k.first,node);
            if(in[node]>in[k.first])low[node]=min(low[node],low[k.first]);
            else if(low[k.first]>in[node])cut[k.second]=1;
            else low[node]=min(low[node],low[k.first]);
        }
}

long long output=0;
int current=0;

void dfs_cnt(int node)
{
    if(been[node])return;
    been[node]=1;
    output+=current;
    current++;
    for(auto k:adj[node])
        if(cut[k.second]==0)dfs_cnt(k.first);
}
int main()
{
    scanf("%i%i",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    dfs(1,0);

    for(int i=1;i<=n;i++)been[i]=0;

    for(int i=1;i<=n;i++)
    {
        current=0;
        dfs_cnt(i);
    }

    printf("%lld\n",output);
    return 0;
}
/*
5 5
1 2
2 3
3 1
2 4
2 5
*/
