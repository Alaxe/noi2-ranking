#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 5003
using namespace std;
int n, k;
vector <int> adj[MAXN];
void read()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++)
        {
            int ver;
            cin >> ver;
            adj[ver].push_back(i);
        }
    }
}
int depth[MAXN];
void solve()
{
    long long ans = 1000000000000000000;
    for (int i = 1; i <= n; i++)
    {
        memset(depth, 0, sizeof(depth));
        queue <int> q;
        q.push(i);
        depth[i] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto j: adj[curr])
                if (depth[j] == 0)
                {
                    depth[j] = depth[curr] + 1;
                    q.push(j);
                }
        }
        long long curr = 0;
        bool can = true;
        for (int j = 1; j <= n; j++)
        {
            if (depth[j] == 0)
            {
                can = false;
                break;
            }
            curr += depth[j];
        }
        curr *= k;
        if (can)
            ans = min(ans, curr);
    }
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
