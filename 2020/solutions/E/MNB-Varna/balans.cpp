#include <iostream>
using namespace std;
int main()
{
    int n, s1 = 0, s2 = 0;
    cin >> n;
    char k;
    for ( int br = 1; br <= n; br++ )
    {
        cin.get (k);
        if ( k == 'a') s1++;
        else if ( k == 'b') s1++;
        else if ( k == 'c') s2++;
        else s2++;
    }
    if ( n % 2 != 0 ) cout << 0 << endl;
    else
    {
        if ( s1 != s2 )
        {
            if ( s2 > s1 ) cout << s2 - ( s2 - s1) + s1 << endl;
            else if ( s1 > s2) cout << s2 - ( s2 - s1) + s1 << endl;
        }
        if ( s1 == s2 ) cout << n << endl;
    }
    return 0;
}
