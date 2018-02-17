#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 10);
const int mod = (int)1e9 + 7;

string s;

void read()
{
    cin >> s;
}

int dp[MAXN][MAXN];

int rec(int l, int r)
{
    if(l == r) return 1;
    if(r < l) return 0;

    int &memo = dp[l][r];
    if(memo != -1) return memo;

    memo = 0;
    memo = (memo + rec(l + 1, r)) % mod;
    memo = (memo + rec(l, r - 1)) % mod;
    memo = (memo - rec(l + 1, r - 1) + mod) % mod;

    if(s[l] == s[r]) memo = (memo + 1 + rec(l + 1, r - 1)) % mod;

    return memo;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cout << rec(0, s.size() - 1) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}
