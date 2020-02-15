#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
vector<int>graph[MAXN],ng[MAXN];
set<pair<int,int> >art;
vector<pair<int,int> >edges;
int timer,n,m,used[MAXN],fup[MAXN],tin[MAXN];
void found_one(int a,int b)
{
    art.insert({a,b});
    art.insert({b,a});
}
void dfs(int v,int p=-1)
{
    used[v]=1;
    tin[v]=fup[v]=timer++;
    for(int i=0;i<graph[v].size();i++)
    {
        int nb=graph[v][i];
        if(nb==p)continue;
        if(used[nb]==1)
        {
            fup[v]=min(fup[v],tin[nb]);
        }
        else
        {
            dfs(nb,v);
            fup[v]=min(fup[v],fup[nb]);
            if(fup[nb]>tin[v])found_one(v,nb);
        }
    }
}
void art_bridges()
{
    int timer=0;
    for(int i=1;i<=n;i++)used[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])dfs(i);
    }
}
void build()
{
    for(int i=0;i<m;i++)
    {
        if(art.find(edges[i])==art.end())
        {
            ng[edges[i].first].push_back(edges[i].second);
            ng[edges[i].second].push_back(edges[i].first);
        }
    }
}
int d;
void DFS(int v)
{
    used[v]=1;
    d++;
    for(int i=0;i<ng[v].size();i++)
    {
        int nb=ng[v][i];
        if(!used[nb])DFS(nb);
    }
}
int main()
{
    int u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
       cin>>u>>v;
       edges.push_back({u,v});
       graph[v].push_back(u);
       graph[u].push_back(v);
    }
    art_bridges();
    build();
    int ans=0;
    for(int i=1;i<=n;i++)used[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            d=0;
            DFS(i);
            ans+=((d-1)*d)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/***
5 5
1 2
2 3
3 1
2 4
2 5
*/
