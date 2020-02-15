#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <limits>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5;

vector<int> adj[MAXN+1];
int depth[MAXN+1];
int lowlink[MAXN+1];
stack<int> s;
ll ans;

void dfs(int u, int p=0) {
    s.push(u);
    depth[u] = depth[p]+1;
    lowlink[u] = u;

    for (int v : adj[u])
        if (v != p) {
            if (depth[v]) {
                lowlink[u] = depth[v]<depth[lowlink[u]]? v: lowlink[u];
            } else {
                dfs(v,u);
                lowlink[u] = depth[lowlink[v]]<depth[lowlink[u]]? lowlink[v]: lowlink[u];
            }
        }

    if (lowlink[u] != u) {
        return;
    }

    ll cnt = 0;

    while (s.size() && depth[lowlink[s.top()]] < depth[s.top()]) {
        //cout << s.top() << " ";
        cnt++;
        s.pop();
    }

    //cout << s.top() << "\n";
    cnt++;
    s.pop();

    ans += (cnt*(cnt-1))/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << ans;
}
