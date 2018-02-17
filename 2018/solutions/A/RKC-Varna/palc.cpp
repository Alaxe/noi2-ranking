#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 107
#define MOD 1000000007
int n ;
string a ;

long long dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= 100 ; i ++ ) {
        for ( j = 0 ; j <= 100 ; j ++ ) {
            dp[ i ][ j ] = 0 ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ i ][ i ] = 1 ;
    }
    int len ;
    for ( len = 1 ; len <= n ; len ++ ) {
        for ( i = 1 ; i + len <= n ; i ++ ) {
            j = i + len ;
            dp[ i ][ j ] = ( dp[ i + 1 ][ j ] + dp[ i ][ j - 1 ] ) % MOD ;
            dp[ i ][ j ] = ( dp[ i ][ j ] + MOD - dp[ i + 1 ][ j - 1 ] ) % MOD ;
            if ( a[ i - 1 ] == a[ j - 1 ] ) {
                dp[ i ][ j ] = ( dp[ i ][ j ] + dp[ i + 1 ][ j - 1 ] + 1 ) % MOD ;
            }
        }
    }
    cout << dp[ 1 ][ n ] << "\n" ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
