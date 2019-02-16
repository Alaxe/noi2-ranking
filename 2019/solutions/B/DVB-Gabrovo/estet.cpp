#include <iostream>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], l[MAXN][2];
int t1[MAXN], t2[MAXN];

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
}

void update(int p, int q, int t)
{
    for (int i = p; i < MAXN; i += i & (-i))
    {
        if (t == 1) t1[i] = max(t1[i], q);
        if (t == 2) t2[i] = max(t2[i], q);
    }
}

int query(int p, int t)
{
    int res = 0;
    for (int i = p; i >= 1; i -= i & (-i))
    {
        if (t == 1) res = max(res, t1[i]);
        if (t == 2) res = max(res, t2[i]);
    }
    return res;
}

int main()
{
    Init();

    for (int i = 1; i <= n; ++ i)
    {
        l[i][0] = query(a[i] - 1, 1) + 1;
        update(a[i], l[i][0], 1);
        l[i][0] = max(l[i][0], l[i - 1][0]);
    }
    for (int i = n; i >= 1; -- i)
    {
        l[i][1] = query(a[i] - 1, 2) + 1;
        update(a[i], l[i][1], 2);
        l[i][1] = max(l[i][1], l[i + 1][1]);
    }

    int ans = 0;
    for (int i = 1; i < n; ++ i)
    {
        // cout << l[i][0] << ' ' << l[i][1] << endl;
        ans = max(ans, l[i][0] + l[i][1] - 1);
    }

    cout << ans << endl;
    return 0;
}

/*
4
2 1 5 3
----------
3
1 5 5
*/
