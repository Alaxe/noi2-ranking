#include <bits/stdc++.h>
#define MAXN 200001
#define endl '\n'
using namespace std;
int n, a, b;
vector <int> v[MAXN];

void input()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cin >> a >> b;
}

bool used[MAXN];
int lvl[MAXN][2];
int clr[MAXN];

void dfs(int temp, int pr, int ind)
{
    lvl[temp][ind] = lvl[pr][ind] + 1;

    for (int i = 0; i < v[temp].size(); i++)
        if (v[temp][i] != pr)
            dfs(v[temp][i], temp, ind);
}

void init()
{
    int cnt1 = 0;
    int cnt2 = 0;
    lvl[0][0] = lvl[0][1] = 0;
    dfs(a, 0, 0);
    dfs(b, 0, 1);
    int sz = 0;

    for (int i = 1; i <= n; i++)
    {
        if (lvl[i][0] < lvl[i][1])
        {
            clr[i] = 0;
            cnt1++;
        }
        else if (lvl[i][0] > lvl[i][1])
        {
            clr[i] = 1;
            cnt2++;
        }
        else sz++;
    }


    if (cnt1 < cnt2)
        swap(cnt1, cnt2);

    if (sz + cnt2 >= cnt1)
    {
        cout << cnt1 << endl;
    }
    else
        cout << cnt2 + sz << endl;
}

/**
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    init();

    return 0;
}
