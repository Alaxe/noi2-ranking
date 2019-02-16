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

const int MAXN = 100000;

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int dp[MAXN][2];

int F(int idx, bool smaller) {
    if (idx == n - 1) return 1;
    if (dp[idx][smaller] != -1) return dp[idx][smaller];
    int ans = F(idx + 1, smaller);
    if (!smaller) {
        if (a[idx] < a[idx + 1]) chkmax(ans, F(idx + 1, smaller) + 1);
        if (a[idx] > a[idx + 1]) chkmax(ans, F(idx + 1, true) + 1);
    }
    else if (smaller && a[idx] > a[idx + 1]) chkmax(ans, F(idx + 1, smaller) + 1);
    return dp[idx][smaller] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cout << (max(F(0, false), F(0,  true))) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();

    return EXIT_SUCCESS;
}
