#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 200003
using namespace std;
int n;
vector <int> adj[MAXN];
int a, b;
void read()
{
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> a >> b;
}
int par[MAXN], depth[MAXN];
int min_leaf[MAXN], max_leaf[MAXN], leaf_depth[MAXN];
int cnt_leaves;
void dfs(int ver)
{
    min_leaf[ver] = INT_MAX;
    max_leaf[ver] = 0;
    for (auto i: adj[ver])
        if (i != par[ver])
    {
        par[i] = ver;
        depth[i] = depth[ver] + 1;
        dfs(i);
        min_leaf[ver] = min(min_leaf[ver], min_leaf[i]);
        max_leaf[ver] = max(max_leaf[ver], max_leaf[i]);
    }
    if (adj[ver].size() == 1 && ver != a)
    {
        leaf_depth[++cnt_leaves] = depth[ver];
        min_leaf[ver] = max_leaf[ver] = cnt_leaves;
    }
}
int tr[MAXN<<2];
void build(int v, int l, int r)
{
    if (l == r)
    {
        tr[v] = leaf_depth[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) + 1, mid + 1, r);
    tr[v] = max(tr[v << 1], tr[(v << 1) + 1]);
}
int get(int v, int l, int r, int x, int y)
{
    if (x > y)
    return 0;
    if (l > y || r < x)
        return 0;
    if (l >= x && r <= y)
        return tr[v];
    int mid = (l + r) >> 1;
    return max(get(v << 1, l, mid, x, y), get((v << 1) + 1, mid + 1, r, x, y));
}
void solve()
{
    depth[a] = 1;
    cnt_leaves = 0;
    dfs(a);
    build(1, 1, cnt_leaves);
    int ver = par[b];
    int ans = 0;
    while (ver != a)
    {
        int max_path_b = depth[b] - depth[ver] + 1;
        int curr = max(get(1, 1, cnt_leaves, min_leaf[ver], min_leaf[b] - 1), get(1, 1, cnt_leaves, max_leaf[b] + 1, max_leaf[ver]));
        if (curr != 0)
            max_path_b += curr - depth[ver];
        int max_path_a = depth[ver] - depth[a];
        curr = max(get(1, 1, cnt_leaves, 1, min_leaf[ver] - 1), get(1, 1, cnt_leaves, max_leaf[ver] + 1, cnt_leaves));
        max_path_a = max(max_path_a, curr - depth[a] + 1);
        ans = max(ans, min(max_path_b, max_path_a));
        ver = par[ver];
    }
    int max_path_b = get(1, 1, cnt_leaves, min_leaf[b], max_leaf[b]) - depth[b] + 1;
    int max_path_a = depth[b] - depth[a];
    max_path_a = max(max_path_a, max(get(1, 1, cnt_leaves, 1, min_leaf[b] - 1), get(1, 1, cnt_leaves, max_leaf[b] + 1, cnt_leaves)) - depth[a] + 1);
    ans = max(ans, min(max_path_b, max_path_a));
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read();
    solve();
}
