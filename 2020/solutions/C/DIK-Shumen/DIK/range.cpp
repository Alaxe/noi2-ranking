#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 17), MAXX = 100010;

int n, m, p[MAXN], cnt[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int x;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        p[x] ++;
    }

    for (int i = 1; i <= MAXX; i ++)
        cnt[i] = cnt[i - 1] + p[i];

    cin >> m;
    int a, b;
    for (int i = 0; i < m; i ++)
    {
        cin >> a >> b;
        cout << cnt[b] - cnt[a - 1] << endl;
    }
    return 0;
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
