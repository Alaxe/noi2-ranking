#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
unsigned long long a[100003];
int n, m, x, y, j;
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> j;
        a[j] ++;
    }
    for(int i = 0; i <= 100000; i ++)
    {
        a[i] = a[i-1] + a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> x >> y;
        cout << a[y] - a[x-1] << endl;
    }
    return 0;
}
