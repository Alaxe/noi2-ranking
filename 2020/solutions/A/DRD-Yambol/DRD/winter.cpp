#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int N=(2e5)+5;

vector < pair <int,bool> > edges;
vector <int> g[N],nb[N];
bool used[N],vis[N];
int intime[N],par[N],low[N];

int ind;

void DFS(int v,int parent)
{
 int i,newv;

 used[v]=true;
 ind++;
 intime[v]=ind;
 low[v]=ind;

  for(i=0;i<g[v].size();i++)
  {
   newv=edges[g[v][i]].first;

    if(!used[newv])
    {
     par[newv]=v;
     DFS(newv,v);

     low[v]=min(low[v],low[newv]);

      if(low[newv]>intime[v])
      {
       edges[g[v][i]].second=true;
       edges[(g[v][i]^1)].second=true;
      }
    }
    else
    {
      if(par[v]!=newv)
       low[v]=min(low[v],intime[newv]);
    }
  }
}

Int viscnt;

void Recurse(int v)
{
 int i;

 vis[v]=true;
 viscnt++;

  for(i=0;i<nb[v].size();i++)
  {
   if(!vis[nb[v][i]])
    Recurse(nb[v][i]);
  }
}

int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

int n,m,i,j,u,v,sz;
Int curcnt,ans;

cin>>n>>m;

 for(i=1;i<=m;i++)
 {
  cin>>u>>v;

  edges.push_back(make_pair(v,false));
  edges.push_back(make_pair(u,false));

  sz=edges.size();
  g[u].push_back(sz-2);
  g[v].push_back(sz-1);
 }

DFS(1,0);

 for(i=1;i<=n;i++)
 {
   for(j=0;j<g[i].size();j++)
   {
     if(edges[g[i][j]].second)
      continue;

    nb[i].push_back(edges[g[i][j]].first);
   }
 }

ans=0;
 for(i=1;i<=n;i++)
 {
   if(!vis[i])
   {
    viscnt=0;
    Recurse(i);
    curcnt=viscnt*(viscnt-1)/2;
    ans+=curcnt;
   }
 }

cout<<ans<<"\n";

return 0;
}
