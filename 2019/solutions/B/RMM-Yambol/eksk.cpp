# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <vector>
using namespace std;
vector <int> g[200002];
int par[200002];
bool vis[200002];
int path[200002];
int ansersA[200002];
int ansersB[200002];
int A,B;
int pathB;
int ans=0;
vector <int> q;

void dfs(int v)
{
    //cout<<v<<endl;
    vis[v]=1;
    int i,j;
    int sum=0;
    for(i=0;i<g[v].size();i++)
    {
        if(vis[g[v][i]])continue;
        par[g[v][i]]=v;
        dfs(g[v][i]);
        sum=max(sum,path[g[v][i]]);
    }
    path[v]=sum+1;
    //cout<<v<<"&&"<<path[v]<<endl;
    if(v==B){path[v]=0;pathB=sum+1;}
}
int main()
{
int n;
scanf("%d",&n);
int i,j,u,v;
for(i=1;i<n;i++)
{
     scanf("%d%d",&u,&v);
     g[u].push_back(v);
     g[v].push_back(u);
}
scanf("%d%d",&A,&B);
par[A]=0;
dfs(A);
ans = min (path[A],pathB);
//cout<<path[A]<<" " <<pathB<<endl;
//cout<<ans<<endl;
 v=B;
q.push_back(B);
while(v!=A)
{
    v=par[v];
    q.push_back(v);
}

int maxsum;
ansersA[par[A]]=0;
for(i=q.size()-1;i>0;i--)
{
    maxsum=0;
    v = q[i];
    u = q[i-1];
   // cout<<v<<":\n";
    for(j=0;j<g[v].size();j++)
    {
     //   cout<<"**"<<g[v][j]<<" "<<par[g[v][j]]<<endl;
        if(par[g[v][j]]!=v)continue;
        if(g[v][j]==u)continue;
        maxsum=max(maxsum,path[g[v][j]]);
    }
   // cout<<maxsum<<endl;
    ansersA[v]=max((int)(maxsum + q.size() - i),ansersA[par[v]]);
    ansersB[v]=maxsum + i + 1 ;
   // cout<<v<<" "<<ansersA[par[v]]<<" "<<ansersB[v]<<" "<<ansersA[v]<<endl;
    ans = max(ans, min(ansersA[par[v]],ansersB[v]));
}
printf("%d\n",ans);
}
/*
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

*/
