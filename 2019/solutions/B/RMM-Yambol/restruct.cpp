# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <vector>
# include <queue>
using namespace std;
vector <int> g[5002];
int vis[5002];
int lev[5002];
int n;
long long solve(int v)
{
    int w=n;
    int i,j,x;
    long long sum=1;
    queue <int> q;
    q.push(v);
    vis[v]=v;
    lev[v]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        w--;
        for(i=0;i<g[x].size();i++)
        {
            if(vis[g[x][i]]==v)continue;
            lev[g[x][i]]=lev[x]+1;
            sum+=(lev[x]+1);
            vis[g[x][i]]=v;
            q.push(g[x][i]);
    }}
    if(w>0)return 1e15;
    return sum;
}
int main()
{
int K;
scanf("%d%d",&n,&K);
int i,j,x,y,k;
for(i=1;i<=n;i++)
{
    scanf("%d",&k);
    for(j=1;j<=k;j++)
    {
        scanf("%d",&x);
        g[x].push_back(i);
    }
}
long long sum=1e15,p;
for(i=1;i<=n;i++)
{ //cout<<i<<" "<<sum<<endl;
  p=  solve(i);
if(p<sum)sum=p;
}
//cout<<sum<<" "<<i<<endl;
sum*=K;
printf("%lld\n",sum);
}
