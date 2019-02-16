#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
using namespace std;
int incr[MAXN];
int decr[MAXN];
int n;
int arr[MAXN];
int tr[MAXN<<2];
void update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        tr[v] = max(tr[v], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(v << 1, l, mid, pos, val);
    else
        update((v << 1) + 1, mid + 1, r, pos, val);
        tr[v] = max(tr[v << 1], tr[(v << 1) + 1]);
}
int get(int v, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l > y || r < x)
        return 0;
    if (l >= x && r <= y)
        return tr[v];
    int mid = (l + r) >> 1;
    return max(get(v << 1, l, mid, x, y), get((v << 1) + 1, mid + 1, r, x, y));
}
void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        incr[i] = get(1, 1, 100000, 1, arr[i]-1) + 1;
        update(1, 1, 100000, arr[i], incr[i]);
    }
    memset(tr, 0, sizeof(tr));
    for (int i = n; i >= 1; i--)
    {
        decr[i] = get(1, 1, 100000, 1, arr[i]-1) + 1;
        update(1, 1, 100000, arr[i], decr[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    ans = max(ans, incr[i] + decr[i] - 1);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read();
    solve();
}
