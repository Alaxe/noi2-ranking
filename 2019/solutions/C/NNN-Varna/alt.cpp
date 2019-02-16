#include <bits/stdc++.h>
using namespace std;
int k, m, n, ans=0;
int rfsna(int x, int d)
{
    if (d==n) return 1;
    int res=0;
    if (x+k<m) res+=rfsna(x+k, d+1);
    if (x-k>0) res+=rfsna(x-k, d+1);
    return res;
}
int main()
{
    int i;
    cin >> k >> m >> n;
    for (i=1; i<m; i++) ans+=rfsna(i, 1);
    cout << ans << endl;
}
