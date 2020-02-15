#include <bits/stdc++.h>

#pragma GCC optimize "-O3"

#define endl '\n'
#define trace(x) cerr << #x << " = " << x << endl

using namespace std;

const int MAXN = 205;
const int MAXW = 205;

int n, w1, w2;
int a[MAXN];
int dp[MAXN][MAXW][MAXW];

int f(int idx, int c1, int c2) {
    if (idx == n) {
        return 0;
    }

    if ((c1 + c2) == 0) {
        return 0;
    }

    int &r = dp[idx][c1][c2];

    if (r != -1) {
        return r;
    }

    int answer = f(idx + 1, c1, c2);
    if ((c1 - a[idx]) >= 0) {
        answer = max(answer, f(idx + 1, c1 - a[idx], c2) + a[idx]);
    }
    if ((c2 - a[idx]) >= 0) {
        answer = max(answer, f(idx + 1, c1, c2 - a[idx]) + a[idx]);
    }

    return r = answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w1 >> w2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << f(0, w1, w2) << endl;

    return EXIT_SUCCESS;
}
