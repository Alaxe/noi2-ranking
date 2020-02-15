#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100002], b[100002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p, q;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    cin >> m;
    int last=1;
    for (int i=0; i<n; i++)
    {
        for (int j=last; j<=a[i]; j++) b[j]=n-i;
        last=a[i]+1;
    }
    for (int i=0; i<m; i++)
    {
        cin >> p >> q;
        cout << b[p]-b[q+1] << endl;
    }
    return 0;
}
