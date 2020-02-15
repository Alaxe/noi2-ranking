#include<iostream>
using namespace std;

int a[27] ;

void ZapalniA ( string b )
    {
    for ( int i = 0 ; i < b . size ( ) ; i++ )
        a[b[i]-'a']++ ;
    }

bool StavaZaZamiana ( string b , int p , char bp )
    {
    int n = b . size ( ) / 2 ;
    if ( a[bp-'a'] >= n ) return false ;
    if ( b[p] - bp == 0 ) return false ;
    if ( b[p+1] == b[p+2] && b[p+1] == bp ) return false ;
    return true ;
    }

string Zameni ( string b , int p )
    {
    int n = b . size ( ) / 2 ;

    if ( StavaZaZamiana ( b , p , 'a' ) ) { b[p] = 'a' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'b' ) ) { b[p] = 'b' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'c' ) ) { b[p] = 'c' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'd' ) ) { b[p] = 'd' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'e' ) ) { b[p] = 'e' ; return b ; }

    if ( StavaZaZamiana ( b , p , 'f' ) ) { b[p] = 'f' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'g' ) ) { b[p] = 'g' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'h' ) ) { b[p] = 'h' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'i' ) ) { b[p] = 'i' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'j' ) ) { b[p] = 'j' ; return b ; }

    if ( StavaZaZamiana ( b , p , 'k' ) ) { b[p] = 'k' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'l' ) ) { b[p] = 'l' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'm' ) ) { b[p] = 'm' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'n' ) ) { b[p] = 'n' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'o' ) ) { b[p] = 'o' ; return b ; }

    if ( StavaZaZamiana ( b , p , 'p' ) ) { b[p] = 'p' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'q' ) ) { b[p] = 'q' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'r' ) ) { b[p] = 'r' ; return b ; }
    if ( StavaZaZamiana ( b , p , 's' ) ) { b[p] = 's' ; return b ; }
    if ( StavaZaZamiana ( b , p , 't' ) ) { b[p] = 't' ; return b ; }

    if ( StavaZaZamiana ( b , p , 'u' ) ) { b[p] = 'u' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'v' ) ) { b[p] = 'v' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'w' ) ) { b[p] = 'w' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'x' ) ) { b[p] = 'x' ; return b ; }
    if ( StavaZaZamiana ( b , p , 'y' ) ) { b[p] = 'y' ; return b ; }

    if ( StavaZaZamiana ( b , p , 'z' ) ) { b[p] = 'z' ; return b ; }
    }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    string p ;
    cin >> p ;
    ZapalniA ( p ) ;

    for ( int i = 2 ; i < p . size ( ) ; i++ )
        if ( p[i] == p[i-1] && p[i-1] == p[i-2] ) p = Zameni ( p , i ) ;
    ZapalniA( p ) ;
    int n = p . size ( ) / 2 ;
    for ( int i = 0 ; i < p . size ( ) ; i++ )
        if ( a[p[i]-'0'] > n ) p = Zameni ( p , i ) ;

    cout << p << endl ;
    return 0 ;
}
