#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int64_t l, r;
int z;

void read()
{
    cin >> l >> r >> z;
}

int64_t dp[64][64][2][2], bound;

int64_t rec(int64_t i, int cnt, int has_began, int is_less)
{
    if(i == -1)
    {
        if(!has_began) return 0;
        if(cnt == z) return 1;
        return 0;
    }

    int64_t &memo = dp[i][cnt][has_began][is_less];
    if(memo != -1) return memo;

    memo = 0;

    int high = ((bound >> i) & 1ll);
    if(is_less) high = 1;

    for(int bit = 0; bit <= high; bit++)
        memo += rec(i - 1, cnt + (has_began) * (bit == 0), has_began | (bit == 1), is_less | (bit < high));

    return memo;
}

int64_t eval(int64_t x)
{
    if(x == 0) return 0;
    bound = x;
    memset(dp, -1, sizeof(dp));
    return rec(61, 0, 0, 0);
}

void solve()
{
    cout << eval(r) - eval(l - 1) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}
