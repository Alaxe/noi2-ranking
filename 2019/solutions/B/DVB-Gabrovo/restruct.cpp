#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 5005;

int n, k;
vector<int> g[MAXN];

int vis[MAXN];
long long tot;
vector<int> ng[MAXN];

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    {
        int m;
        cin >> m;

        for (int j = 1; j <= m; ++ j)
        {
            int adj;
            cin >> adj;
            g[adj].push_back(i);
        }
    }
}

int BFS(int u)
{
    tot = 0;
    for (int i = 1; i <= n; ++ i)
    {
        vis[i] = 0;
        ng[i].clear();
    }

    queue<int> q;
    q.push(u);
    vis[u] = u;

    int cnt = n;
    while (!q.empty())
    {
        u = q.front();
        q.pop();

        cnt--;

        for (int v : g[u])
        {
            if (vis[v] == 0)
            {
                vis[v] = u;
                q.push(v);
            }
        }
    }

    if (cnt != 0) return 1;

    for (int i = 1; i <= n; ++ i)
    {
        if (vis[i] != i)
        {
            ng[vis[i]].push_back(i);
        }
    }

    return 0;
}

int DFS(int u)
{
    int res = 0;
    for (int v : ng[u])
    {
        res += DFS(v);
    }
    tot += ++res;
    return res;
}

int main()
{
    Init();

    long long ans = 1ll << 60;
    for (int i = 1; i <= n; ++ i)
    {
        if (BFS(i) == 1) continue;
        DFS(i);
        ans = min(ans, tot * k);
        // cout << i << ' ' << tot << endl;
    }

    cout << ans << endl;
    return 0;
}

/*
4 100
1 4
3 1 3 4
2 1 2
1 3
----------
9 100
7 2 3 4 5 6 7 8
1 1
2 1 2
1 2
2 4 1
1 5
2 1 5
1 5
1 1
*/
