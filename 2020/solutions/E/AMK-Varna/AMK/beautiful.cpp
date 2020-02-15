#include<iostream>
using namespace std;
int main()
{
    long long  n, br = 0, i, a = 1, b, t = 0;
    cin >> n;
    if( n < 10 )
    {
        cout << n << endl;
    }
    b = n;
    while( b > 0 )
    {
        b = b/10;
        ++br;
    }
    for( i = 0 ; i < br ; ++i )
    {
        a = a*10;
    }
    for( i = 1 ; i < br ; ++i )
    {
        t = t*10 + 9;
    }
    long long k = 1;
    for( i = 1 ; i < br ; ++i )
    {
        k = k*10 + 1;
    }
    if( n%k == 0 )
    {
    cout << ( br - 1 )*9 + n/t << endl;
    }
    else if( n > k*( br - 1 ) )
    {
    cout << ( br - 1 )*9 + ( n - t )/t + 1 << endl;
    }
    else
    {
    cout << ( br - 1 )*9 + ( n - t )/t << endl;
    }
    return 0;
}
