#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 2e5 + 15;

int n, Q;
struct platform{

    int l, r, y;
    bool operator <(const platform &other)
    {
        if(y != other.y)
            return y < other.y;
        return  l < other.l;
    }

}a[N];

int seg[4 * N], lazy[4 * N];
void refresh(int pos, int low, int high)
{
    if(lazy[pos] == 0)
        return;

    seg[pos] = lazy[pos];
    if(low < high)
    {
        lazy[pos * 2] = lazy[pos];
        lazy[pos * 2 + 1] = lazy[pos];
    }
    lazy[pos] = 0;
}

void update(int pos, int low, int high, int l, int r, int x)
{
    refresh(pos, low, high);
    if(l <= low && r >= high)
    {
        lazy[pos] = x;
        refresh(pos, low, high);
        return;
    }
    if(l > high || r < low)
        return;

    int mid = (low + high) / 2;
    update(pos * 2, low, mid, l, r, x);
    update(pos * 2 + 1, mid + 1, high, l, r, x);
}

int query(int pos, int low, int high, int x)
{
    refresh(pos, low, high);
    if(low == high)
        return seg[pos];

    int mid = (low + high) / 2;
    if(x <= mid)
        return query(pos * 2, low, mid, x);
    else
        return query(pos * 2 + 1, mid + 1, high, x);
}

int Query(int x)
{
    if(x == 0)
        return 0;
    return query(1, 1, N - 4, x);
}

int lefty[N], righty[N];

vector <int> ans;
int mem[N];

int solve(int x)
{
    if(x == 0)
        return 0;
    if(mem[x] != -1)
        return mem[x];

    mem[x] = 1 + min(solve(lefty[x]), solve(righty[x]));
    return mem[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y, d;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y >> d;

        a[i].l = x;
        a[i].r = x + d - 1;
        a[i].y = y;
    }
    sort(a + 1, a + n + 1);
    a[0].y = 0;
    a[0].l = 0;
    a[0].r = N - 4;

    for(int i = 1; i <= n; i++)
    {
        lefty[i] = Query(a[i].l - 1);
        righty[i] = Query(a[i].r + 1);

        update(1, 1, N - 4, a[i].l, a[i].r, i);
    }

    /*
    for(int i = 1; i <= n; i++)
    {
        cout << a[i].l << " " << a[i].r << " " << a[i].y << " : ";
        cout << a[lefty[i]].l << " " << a[lefty[i]].r << " " << a[lefty[i]].y << " , ";
        cout << a[righty[i]].l << " " << a[righty[i]].r << " " << a[righty[i]].y << endl;
    } */

    memset(mem, -1, sizeof(mem));

    cin >> Q;
    for(int i = 1; i <= Q; i++)
    {
        cin >> x;
        ans.pb(solve(Query(x)));
    }

    for(auto t: ans)
        cout << t << " ";
    cout << endl;


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

