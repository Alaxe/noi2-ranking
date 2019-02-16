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
const int MAXN = 1 << 19;
const int B = (int)3e5 + 42;

struct segment_tree
{
    int lazy[4 * MAXN], tr[4 * MAXN];

    void push(int l, int r, int idx)
    {
        if(lazy[idx] != -1)
        {
            tr[idx] = lazy[idx];
            if(l != r)
            {
                lazy[2 * idx + 1] = lazy[idx];
                lazy[2 * idx + 2] = lazy[idx];
            }

            lazy[idx] = -1;
        }
    }

    void init(int l, int r, int idx)
    {
        lazy[idx] = -1;
        if(l == r)
        {
            tr[idx] = 0;
            return;
        }

        int mid = (l + r) >> 1;
        init(l, mid, 2 * idx + 1);
        init(mid + 1, r, 2 * idx + 2);

        tr[idx] = 0;
    }

    int query(int pos, int l, int r, int idx)
    {
        push(l, r, idx);
        if(pos == l && l == r)
            return tr[idx];

        int mid = (l + r) >> 1;
        if(pos <= mid) return query(pos, l, mid, 2 * idx + 1);
        else return query(pos, mid + 1, r, 2 * idx + 2);
    }

    void set_update(int ql, int qr, int val, int l, int r, int idx)
    {
        push(l, r, idx);
        if(ql > r || qr < l)
            return;

        if(ql <= l && r <= qr)
        {
            lazy[idx] = val;
            push(l, r, idx);
            return;
        }

        int mid = (l + r) >> 1;
        set_update(ql, qr, val, l, mid, 2 * idx + 1);
        set_update(ql, qr, val, mid + 1, r, 2 * idx + 2);
    }
};

int n;
pair<int, pair<int, int> > a[MAXN];

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        a[i] = {y, {x, x + d - 1}};
    }
}

segment_tree t;

void solve()
{
    t.init(0, B, 0);
    sort(a, a + n);

    for(int i = 0; i < n; i++)
    {
        int l = a[i].second.first, r = a[i].second.second;
        int dp = 1 + min(t.query(r + 1, 0, B, 0), t.query(l - 1, 0, B, 0));
        t.set_update(l, r, dp, 0, B, 0);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << t.query(x, 0, B, 0) << " ";
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();
    return 0;
}

/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
