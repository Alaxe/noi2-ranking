#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 200005;

int n, gn, dn;
vector<int> g[MAXN];

int vis[MAXN], d[MAXN];
int opt[MAXN][2];

stack<int> st;
vector<int> p;

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> gn >> dn;
}

void toZero()
{
    for (int i = 1; i <= n; ++ i)
    {
        vis[i] = 0;
    }
}

bool findPath(int u = gn)
{
    vis[u] = 1;

    if (u == dn)
    {
        st.push(dn);
        return 1;
    }

    for (int v : g[u])
    {
        if (vis[v] == 0 and findPath(v))
        {
            st.push(u);
            return 1;
        }
    }

    return 0;
}

void maxDepth(int u)
{
    d[u] = 1;
    for (int v : g[u])
    {
        if (vis[v] != 0 or d[v] != 0) continue;
        maxDepth(v);
        d[u] = max(d[u], d[v] + 1);
    }
}

int main()
{
    Init();

    toZero();
    findPath();
    toZero();

    while (!st.empty())
    {
        p.push_back(st.top());
        vis[p.back()] = 1;
        st.pop();
    }

    for (int i = 0; i < p.size(); ++ i)
    {
        maxDepth(p[i]);
        // cout << p[i] << ' ' << d[p[i]] << endl;
    }

    for (int i = 1; i < p.size() - 1; ++ i)
    {
        opt[i][0] = opt[i - 1][0];
        opt[i][0] = max(opt[i][0], d[p[i]] + i);
    }
    for (int i = p.size() - 2; i >= 1; -- i)
    {
        opt[i][1] = opt[i + 1][1];
        opt[i][1] = max(opt[i][1], d[p[i]] + (int)(p.size()) - 1 - i);
    }

//    for (int i = 0; i < p.size(); ++ i)
//    {
//         cout << opt[i][0] << ' ' << opt[i][1] << endl;
//    }

    int ans = min(d[gn], d[dn]);
    for (int i = 1; i < p.size() - 1; ++ i)
    {
        ans = max(ans, min(opt[i][0], opt[i + 1][1]));
        // cout << opt[i][0] << ' ' << opt[i + 1][1] << endl;
    }
    ans = max(ans, min(d[gn], opt[1][1] + 1));
    ans = max(ans, min(d[dn], opt[p.size() - 2][0] + 1));

    cout << ans << endl;
    return 0;
}

/*
6
1 2
2 3
3 4
4 5
5 6
4 5
----------
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
