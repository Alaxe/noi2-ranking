#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[52][52];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K, le, ri;
    cin >> N >> K;
    le=K-1;
    ri=N-K;
    for (int j=1; j<=ri; j++) a[0][j]=1;
    for (int i=1; i<=le; i++) a[i][0]=1;
    for (int i=1; i<=le; i++)for (int j=1; j<=ri; j++) a[i][j]=a[i-1][j]+a[i][j-1];
    cout << a[le][ri] << endl;
    return 0;
}
