#include <algorithm>
#include <iostream>
#define endl '\n'
using namespace std;

const int MAXN = 100000;

int a[MAXN + 5];

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i)
        cin >> a[i];

    sort(a, a + n);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++ i)
    {
        int p, q;
        cin >> p >> q;

        int u = lower_bound(a, a + n, p) - a;
        int v = lower_bound(a, a + n, q + 1) - a;
        cout << v - u << endl;
    }

    return 0;
}
