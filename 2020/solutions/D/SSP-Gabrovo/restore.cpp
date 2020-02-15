#include<iostream>
using namespace std;

struct ChislaZaZmiana
    {
    bool iz ;
    int pg ;
    } a[10001] ;

void OpraviA ( int b )
    {
    for ( int i = b-1 ; i > 0 ; i-- )
        a[i].pg-- ;
    }

int c[10001] , o[10001] ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    int n ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> c[i] ;
    for ( int i = 1 ; i <= n ; i++ )
        {
        a[i].iz = 0 ;
        a[i].pg = n - i ;
        }

    o[1] = n - c[1] ;
    a[o[1]] . iz = 1 ;
    OpraviA ( o[1] ) ;
    for ( int i = 2 ; i <= n ; i++ )
        {
        int so = n - c[i] ;
        int s1 = c[i] ;
        int stop = 0 ;
        if ( a[so].pg != s1 or a[so].iz == 1 )
            {
            while ( stop == 0 )
                {
                if ( a[so].pg == s1 && a[so].iz == 0 ) stop = 1 ;
                so-- ;
                }
            so++ ;
            }
        o[i] = so ;
        a[o[i]].iz = 1 ;
        OpraviA ( o[i] ) ;
        }

    for ( int i = 1 ; i <= n ; i++ )
        {
        cout << o[i] ;
        if ( i < n ) cout << " " ;
        else cout << endl ;
        }
    return 0 ;
}
