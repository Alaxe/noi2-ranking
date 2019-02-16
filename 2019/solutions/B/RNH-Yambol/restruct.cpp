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

const int MAXN = 5001;

int n, k;
vector<int> pref[MAXN];

void read() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) pref[i].clear();
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        for (int j = 1; j <= len; j++) {
            int person;
            cin >> person;
            pref[i].pb(person);
        }
    }
}

long long ans = LLONG_MAX;
long long curr_ans;
int cnt;
vector<int> g[MAXN];

long long dfs(int node) {
    cnt++;
    if (!SZ(g[node])) {
        curr_ans += k;
        return k;
    }
    long long sum = 0;
    for (int adj : g[node]) sum += dfs(adj);
    curr_ans += sum + k;
    return sum + k;
}

void F(int person, int root) {
    if (person == n + 1) {
        if (root == -1) return;
        curr_ans = 0;
        cnt = 0;
        dfs(root);
        if (cnt == n)  chkmin(ans, curr_ans);
        return;
    }
    for (int parent : pref[person]) {
        g[parent].pb(person);
        F(person + 1, root);
        g[parent].pop_back();
    }
    if (root == -1) F(person + 1, person);
}

void F2(int person, int root) {
    if (person == root) {
        F2(person + 1, root);
        return;
    }
    if (person == n + 1) {
        if (root == -1) return;
        curr_ans = 0;
        cnt = 0;
        dfs(root);
        if (cnt == n)  chkmin(ans, curr_ans);
        return;
    }
    for (int parent : pref[person]) {
        g[parent].pb(person);
        F(person + 1, root);
        g[parent].pop_back();
    }
}

void solve() {
    for (int i = 1; i <= n; i++) g[i].clear();
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!SZ(pref[i])) {
            root = i;
            break;
        }
    }
    if (root == -1) F(1, -1);
    else F2(1, root);
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
