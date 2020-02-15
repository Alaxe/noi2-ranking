#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n,m,k;
struct edge{
    int b,e,used;
    edge(){}
    edge(int b,int e,int u): b(b), e(e), used(u)  {}
};
struct node{
    int v,ind;
    node(){}
    node(int a,int b): v(a), ind(b) {}
};
edge edges[2*MAXN],ed[2*MAXN];
vector<node> graph[MAXN];
int used[MAXN];
bool f;
void dfs(int b,int e)
{
    if(b == e)
    {
        f = 1;
        return;
    }
    if(f == 1)return;
    used[b] = 1;
    for(int i = 0; i < graph[b].size(); i++)
    {
        if(edges[graph[b][i].ind].used != 1 && !used[graph[b][i].v])
        {
            dfs(graph[b][i].v,e);
        }
    }
}
void dfs2(int s)
{
    if(used[s] == 1)return;
    used[s] = 1;
    k++;
    for(int i = 0; i < graph[s].size(); i++)
    {
        if(edges[graph[s][i].ind].used == 2 && !used[graph[s][i].v])
        {
            dfs2(graph[s][i].v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,j,b,e;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> b >> e;
        graph[b].push_back(node(e,i));
        graph[e].push_back(node(b,i));
        edges[i] = edge(b,e,0);
    }
    for(i = 0; i < m; i++)
    {
        edges[i].used = 1;
        dfs(edges[i].b,edges[i].e);
        if(f == 1)
        {
            edges[i].used = 2;
        }
        else edges[i].used = 0;
        f = 0;
        for(j = 1; j <= n; j++)
        {
            used[j] = 0;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dfs2(i);
        ans = ans + ((k-1)*k)/2;
        k = 0;
    }
    cout << ans << endl;
    return 0;
}
/**
5 5
1 2
2 3
3 1
2 4
2 5
*/
