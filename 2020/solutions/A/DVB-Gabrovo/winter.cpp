#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct edge
{
    int u, v;
    bool used;
};

edge e[MAXM];

int n, m;
queue<int> gg[MAXN];

int vis[MAXN], par[MAXN];
pair<int, int> special_transit;

int comp[MAXN];
vector<int> group[MAXN];

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> e[i].u >> e[i].v;
        e[i].used = 0;

        gg[e[i].u].push(i);
        gg[e[i].v].push(i);
    }

    for (int i = 1; i <= n; ++ i)
    {
        comp[i] = i;
        group[i].push_back(i);
    }
}

void DFS(int u = 1, int p = 0)
{
    // cerr << u << endl;

    vis[u] = 1;
    par[u] = p;

    while (!gg[u].empty())
    {
        // cerr << "edge: " << gg[u].front() << endl;

        if (e[gg[u].front()].used)
        {
            gg[u].pop();
            continue;
        }
        else e[gg[u].front()].used = 1;

        if (comp[e[gg[u].front()].u] == comp[e[gg[u].front()].v]) continue; // ignore

        int v;
        if (comp[e[gg[u].front()].u] == comp[u]) v = e[gg[u].front()].v;
        if (comp[e[gg[u].front()].v] == comp[u]) v = e[gg[u].front()].u;
        gg[u].pop();

        v = comp[v];

        if (vis[v] == 0)
        {
            DFS(v, u);
            if (special_transit.first == u)
            {
                u = special_transit.second;
                special_transit = make_pair(0, 0);
            }
            if (comp[u] != u) return;
        }
        else
        {
            int t = u;
            int mes = 0, mev = 0, mvs = 0, mvv = 0;

            // cerr << "cycle found u = " << u << " v = " << v << endl;

            while (true)
            {
                if (mvs < group[t].size())
                {
                    mvs = group[t].size();
                    mvv = t;
                }
                if (mes < gg[t].size())
                {
                    mes = gg[t].size();
                    mev = t;
                }

                if (t == v) break;
                else t = par[t];
            }

            swap(gg[mev], gg[mvv]);

            t = u;
            while (true)
            {
                if (t != mvv)
                {
                    while (!gg[t].empty())
                    {
                        gg[mvv].push(gg[t].front());
                        gg[t].pop();
                    }
                    while (!group[t].empty())
                    {
                        group[mvv].push_back(group[t].back());
                        comp[group[t].back()] = mvv;
                        group[t].pop_back();
                    }
                }

                if (t == v) break;
                else t = par[t];
            }

            special_transit = make_pair(v, mvv);
            return;
        }
    }
}

int main()
{
    Init();

    DFS();

    long long ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        ans += 1ll * group[i].size() * (group[i].size() - 1) / 2;
        // cerr << i << ' ' << group[i].size() << endl;
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
-------------------
16 19
1 2
1 6
2 3
2 14
3 4
3 7
4 5
4 9
5 6
5 10
6 15
6 16
7 8
7 9
8 9
10 11
10 12
11 13
12 13
*/

