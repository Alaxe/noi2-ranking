#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int64_t n;

void read()
{
    cin >> n;
}

void solve()
{
    int64_t low = 0, high = (int64_t)1e16, mid, ret;
    while(low <= high)
    {
        mid = (low + high) >> 1ll;

        int64_t x = 30ll * mid + 26ll;
        if(x >= n)
            ret = x, high = mid - 1;
        else
            low = mid + 1;
    }

    cout << ret << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();
    return 0;
}
