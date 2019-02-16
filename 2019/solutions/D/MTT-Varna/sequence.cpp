#include <iostream>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, tms=1;
    long long els=-1, plc=0;
    cin >> n >> k;
    for (int i=1; i<=n; i++) els+=2, plc+=els;
    while (k>tms) els+=2, plc+=els, tms+=2;
    if (k%2==0) cout << plc-els+n << endl;
    else cout << plc-n+1 << endl;
    return 0;
}
