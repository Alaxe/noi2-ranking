#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int TSIZE = (1 << 20);
const int MAXH = 1e5 + 5;

int n;
int a[MAXN];
int tree[2][TSIZE];

int get_index(int index)
{
    return (TSIZE >> 1) + index;
}

void update(int index, int value, int t)
{
    index = get_index(index);

    tree[t][index] = value;
    for(int i = index >> 1; i > 0; i >>= 1)
    {
        tree[t][i] = max(tree[t][i * 2], tree[t][i * 2 + 1]);
    }
}

int query(int l, int r, int t)
{
    if(l > r) return 0;
    l = get_index(l); r = get_index(r);

    if(l == r)
    {
        return tree[t][l];
    }
    int ans = max(tree[t][l], tree[t][r]);

    while(l + 1 != r)
    {
        if((l & 1) == 0) ans = max(tree[t][l + 1], ans);
        if((r & 1) == 1) ans = max(tree[t][r - 1], ans);
        l >>= 1; r >>= 1;
    }
    return ans;
}

void read_input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int temp[2][MAXN];

void solve()
{
    update(a[0], 1, 0);
    update(a[0], 1, 1);
    for(int i = 1; i < n; i++)
    {
        int first = query(1, a[i] - 1, 0) + 1;
        int second = query(a[i] + 1, MAXH, 1) + 1;

        if(temp[0][a[i]] < first)
        {
            temp[0][a[i]] = first;
            update(a[i], first, 0);
        }
        if(temp[1][a[i]] < second || temp[1][a[i]] < first)
        {
            int val = max(first, second);
            temp[1][a[i]] = val;
            update(a[i], val, 1);
        }
    }
    int fe = query(1, MAXH, 0);
    int se = query(1, MAXH, 1);

    int ans = max(fe, se);

    printf("%d\n", ans);
}

int main()
{
    read_input();
    solve();

    return 0;
}

/*
4
2 1 5 3
*/

/*
3
1 5 5
*/

/*
6
1 2 3 5 4 3
*/

/*
9
1 3 2 4 5 1 2 3 1
*/

/*
14
1 3 2 4 8 1 2 3 4 5 6 7 1 2
*/

/*
11
1 2 2 2 5 6 7 1 3 2 2
*/
