#include<iostream>
using namespace std;
int main ()
{
    int n, mi = 0, mx = 100001, t, c1 = 0, c2 = 0;
    cin >> n;
    for ( int i = 0; i < n; ++i )
    {
        cin >> t;
        if ( mi < t ) mi = t;
        else ++c1;

        if ( mx > t ) mx = t;
        else ++c2;
    }

    if( c1 > c2 ) cout << n-c2 << endl;
    else cout << n-c1 << endl;

    return 0;
}
