#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair <int, int>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m;
vector <int> nb[N];
pii edges[M];
bool vis[N];

int adj(int id, int v)
{
    if(id == -1)
        return -1;
    return ((edges[id].first == v) ? edges[id].second : edges[id].first);
}

bool is_bridge[M];
int low[N], disc[N], timer;
void DFS_bridges(int v, int le = -1)
{
    vis[v] = true;
    low[v] = disc[v] = ++timer;
    for(int id: nb[v])
    {
        int u = adj(id, v);
        if(!vis[u])
        {
            DFS_bridges(u, id);
            low[v] = min(low[v], low[u]);
        }
        else
        {
            if(u != adj(le, v))
                low[v] = min(low[v], low[u]);
        }
    }

    if(le != -1)
        if(low[v] == disc[v])
            is_bridge[le] = true;
}

int comp_sz;
int DFS(int v)
{
    vis[v] = true;
    comp_sz++;
    for(int id: nb[v])
    {
        if(!is_bridge[id] && !vis[adj(id, v)])
            DFS(adj(id, v));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int u, v;

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edges[i] = mp(u, v);
        nb[u].pb(i);
        nb[v].pb(i);
    }

    DFS_bridges(1);
//    for(int i = 1; i <= m; i++)
//        cerr << is_bridge[i] << ((i == m) ? '\n' : ' ');

    memset(vis, false, sizeof(vis));
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
        {
            comp_sz = 0;
            DFS(i);
            ans += ((ll)comp_sz * (comp_sz - 1)) / 2;
        }

    cout << ans << endl;

    return 0;
}

/*

5 5
1 2
2 3
3 1
2 4
2 5

4 4
1 2
2 3
3 4
4 1

5 6
1 2
1 3
1 5
3 4
3 5
4 5

7 7
1 2
1 3
2 4
4 5
2 6
3 6
6 7

*/
