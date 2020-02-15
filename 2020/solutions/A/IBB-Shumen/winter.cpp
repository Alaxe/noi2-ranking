#include <bits/stdc++.h>
using namespace std;
const int maxn=2*131072;
long long int n,m,br;
int used[maxn];
vector<int>g[maxn];
vector<int>v[maxn];
int timer,tin[maxn],fup[maxn];
vector<pair<int,int> >k;
///----------------------------------------------
void read()
{
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
///----------------------------------------------
void init_used()
{
    for(int i=0;i<=n;i++)
    {
        used[i]=0;
    }
}
///----------------------------------------------
void dfs(int v, int p=-1)
{
    used[v]=true;
    tin[v]=fup[v]=timer++;
    for(int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if(to==p)continue;
        if(used[to])
        {
            fup[v]=min(fup[v],tin[to]);
        }
        else
        {
            dfs(to,v);
            fup[v]=min(fup[v],fup[to]);
            if(fup[to]>tin[v])
            {
                k.push_back(make_pair(v,to));
            }
        }
    }
}
///----------------------------------------------
void find_bridges()
{
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
}
///----------------------------------------------
void dfs2(int j)
{
    used[j]=true;
    for(int i=0;i<v[j].size();i++)
    {
        int nb=v[j][i];
        if(!used[nb])
        {
            br++;
            dfs2(nb);
        }
    }
}
///----------------------------------------------
bool check(int x,int y)
{
    for(int i=0;i<k.size();i++)
    {
        if((min(k[i].first,k[i].second)==min(x,y) && max(k[i].first,k[i].second)==max(x,y)))return false;
    }
    return true;
}
///----------------------------------------------
void solve()
{
    long long int ans=0;
    find_bridges();
    init_used();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            if(check(i,g[i][j])==true)
            {
                v[i].push_back(g[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            br=1;
            dfs2(i);
            ans+=(br*(br-1))/2;
        }
    }
    cout<<ans<<"\n";
}
///----------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve();
    return 0;
}
/*
8 9
1 2
1 3
2 3
1 4
1 7
4 5
5 6
6 7
7 8
*/
