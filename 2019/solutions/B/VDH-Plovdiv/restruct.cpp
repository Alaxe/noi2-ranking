#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> g[5010];
vector <int> g1[5010];
queue <int> q;
int used[5010];
int d[5010];
int n, K, k[5010], r[5010][5010], a[5010];
int bfs(int st)
{
    for (int i=1; i<=n+1; i++) used[i]=0;
    q.push(st);
    used[st]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0; i<g[u].size(); i++)
        {
            if (used[g[u][i]]==0)
            {
                q.push(g[u][i]);
                used[g[u][i]]=1;
                g1[u].push_back(g[u][i]);
            }
        }
    }
}
int s[5010];
int dfs(int st)
{
    for (int i=0; i<g1[st].size(); i++)
    {
        dfs(g1[st][i]);
        s[st]+=s[g1[st][i]];
    }
}
int main()
{

    cin>>n>>K;
    for (int i=1; i<=n; i++)
    {
        cin>>k[i];
        for (int j=0; j<k[i]; j++)
        {
            int u;
            cin>>u;
            a[u]++;
            g[u].push_back(i);
        }
    }
    int maxx=0, maxi=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]>maxx) {maxx=a[i]; maxi=i;}
    }
    bfs(maxi);
    for (int i=0; i<=n; i++) s[i]=1;
    dfs(maxi);
    int br=0;
    for (int i=1; i<=n; i++)
    {
        br+=s[i];
    }
    cout<<br*K<<endl;
}
