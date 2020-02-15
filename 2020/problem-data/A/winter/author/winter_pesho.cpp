#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int n, m;
vector<int> edges[MAXN+1];
vector<int> edgesNoBridges[MAXN+1];
int currentTime;
int times[MAXN+1];
int low[MAXN+1];
bool used[MAXN+1];

void bridges(int u, int p) {
    times[u] = low[u] = ++currentTime;
    for (int v: edges[u]) {
        if (times[v] == 0) {
            bridges(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] < times[u]) {
                edgesNoBridges[u].push_back(v);
                edgesNoBridges[v].push_back(u);
            }
        } else if (v != p) {
            low[u] = min(low[u], low[v]);
            edgesNoBridges[u].push_back(v);
            edgesNoBridges[v].push_back(u);
        }
    }
}

int dfs(int u) {
    if (used[u]) return 0;
    used[u] = true;
    int ans = 1;
    for (int v: edgesNoBridges[u]) {
        if (used[v]) continue;
        ans += dfs(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    bridges(1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        long long br = dfs(i);
        ans += br*(br-1)/2;
    }
    cout << ans << endl;

    return 0;
}
