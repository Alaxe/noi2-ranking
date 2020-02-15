#include<iostream>
using namespace std;

struct ulei
    {
    int b ;
    int v ;
    int o ;
    } ;

struct masiv
    {
    int a1 ;
    int a2 ;
    } a[101] ;

int main()
    {
    //////////////////////////////////////////

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    ulei ul[101] ;
    int n , u , h ;
    cin >> n >> u >> h ;
    cin >> a[0] . a1 ;
    for ( int i = 1 ; i < n ; i++ )
        {
        cin >> a[i] . a1 ;
        int j = i-1 ;
        while ( a[i] . a1 > a[j] . a2 )
            {
            a[j] . a2 = a[i] . a1 ;
            if ( j > 0 ) j-- ;
            }
        }

    ///////////////////////////////////////

    int p = 0 ;
    for ( int i = 0 ; i < n-1 ; )
        {
        if ( a[i] . a1 <= a[i+1] . a1 )
            {
            ul[p] . b = 1 ;
            ul[p] . v = a[i] . a1 ;
            p++ ;
            i++ ;
            continue ;
            }
        int s = a[i] . a1 , iz = 0  ;
        bool stop1 = 0 , stop2 = 0 ;
        while ( stop1 == 0 )
            {
            iz++ ;
            i++ ;
            if ( stop2 == 1 ) stop1 = 1 ;
            if ( a[i] . a1 < a[i+1] . a1 ) stop2 = 1 ;
            if ( i == n-1 ) stop2 = 1 ;
            if ( a[i] . a1 > a[i] . a2 ) stop2 = 1 ;
            }
        ul[p] . b = iz ;
        ul[p] . v = min ( s , a[i] . a1 ) ;
        p++ ;
        }

    int s = 0 ;
    for ( int i = 0 ; i < p ; i++ )
        s = s + (u*ul[i].b) * ul[i].v * h ;

    cout << s << endl ;
    return 0 ;
    }
