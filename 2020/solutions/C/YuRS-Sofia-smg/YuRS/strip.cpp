#include <iostream>
using namespace std;
#define endl '\n'
#define MAXN 55
typedef long long lon;
lon br, k;
lon dp[MAXN][MAXN];
lon recurse(lon from, lon to)
{
    if(from > to) return 0;
    if(from > k || to < k) return 0;
    if(from > br || to < 1) return 0;
    if(from == k && to == k) return 1;
    if(dp[from][to] != 0) return dp[from][to];
    dp[from][to] = recurse(from + 1, to) + recurse(from, to - 1);
    return dp[from][to];
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> br >> k;
    cout << recurse(1, br) << endl;
    return 0;
}
