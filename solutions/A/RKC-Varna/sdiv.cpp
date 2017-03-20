#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 10007

int n ;
string a ;
int x ;
long long mod ;

long long ans ;

long long br[ MAXN ] ;
long long nw[ MAXN ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    cin >> x >> mod ;
}

void solve ( ) {
    ans = 0 ;
    int i , j ;
    for ( i = 0 ; i <= x ; i ++ ) {
        br[ i ] = nw[ i ] = 0 ;
    }
    br[ 0 ] = 1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        int val = ( a[ i ] - '0' ) ;
        for ( j = 0 ; j < x ; j ++ ) {
            nw[ ( ( j * 10 + val ) % x ) ] += br[ j ] ;
            nw[ ( ( j * 10 + val ) % x ) ] %= mod ;
        }
        ans += nw[ 0 ] ;
        ans %= mod ;
        for ( j = 0 ; j < x ; j ++ ) {
            br[ j ] += nw[ j ] ;
            br[ j ] %= mod ;
            nw[ j ] = 0 ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
