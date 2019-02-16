#include <bits/stdc++.h>

#define endl '\n'
#define TRACE(x) cerr << #x << " = " << x << endl
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define L_B lower_bound
#define U_B upper_bound

using namespace std;
template<class T, class T1> inline bool chkmax(T &x, const T1 &y) { return x < y ? x = y, true : false; }
template<class T, class T1> inline bool chkmin(T &x, const T1 &y) { return x > y ? x = y, true : false; }

const int MAXN = 200001;

int n;
vector<int> g[MAXN];
int a, b;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> a >> b;
}

int timestamp = 0;
int used[MAXN];
int level_a[MAXN];
int parent_a[MAXN];
int level_b[MAXN];
int parent_b[MAXN];

void bfs_a(int start) {
    timestamp++;
    queue<int> q;
    used[start] = timestamp;
    level_a[start] = 1;
    parent_a[start] = -1;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int adj : g[now]) {
            if (used[adj] != timestamp) {
                used[adj] = timestamp;
                level_a[adj] = level_a[now] + 1;
                parent_a[adj] = now;
                q.push(adj);
            }
        }
    }
}

void bfs_b(int start) {
    timestamp++;
    queue<int> q;
    used[start] = timestamp;
    level_b[start] = 1;
    parent_b[start] = -1;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int adj : g[now]) {
            if (used[adj] != timestamp) {
                used[adj] = timestamp;
                level_b[adj] = level_b[now] + 1;
                parent_b[adj] = now;
                q.push(adj);
            }
        }
    }
}

void init_path(int a) {
    timestamp++;
    int now = a;
    while (parent_a[now] != -1) {
        used[now] = timestamp;
        now = parent_a[now];
    }
    used[now] = timestamp;
}

bool check_path(int b) {
    int now = b;
    while (parent_b[now] != -1) {
        if (used[now] == timestamp) return false;
        now = parent_b[now];
    }
    return used[now] != timestamp;
}

bool check(int len) {
    for (int i = 1; i <= n; i++) {
        if (level_a[i] == len) {
            init_path(i);
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (level_b[j] == len && check_path(j)) return true;
            }
        }
    }
    return false;
}

void solve() {
    memset(used, 0, sizeof(used));
    bfs_a(a);
    bfs_b(b);
    int ans = 0;
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();

    return EXIT_SUCCESS;
}
