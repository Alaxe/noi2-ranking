#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100007], b[100007];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0, ch = 2;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> b[i];
    }
    a[n-1] = 1;
    for( int i = n-2; i >= 0; i-- )
    {
        for( int j = 0; j <= n-i-b[i]-1; j++ )
        {
            if( a[j] > n-i-b[i]-1 ) a[n-j]++;
        }
        ch = n-i-b[i];
        a[i] = ch;
    }
    for( int i = 0; i < n; i++ ) cout << a[i] << " ";
    cout << endl;
    return 0;
}

/**
6
2 3 0 0 1 0
*/
