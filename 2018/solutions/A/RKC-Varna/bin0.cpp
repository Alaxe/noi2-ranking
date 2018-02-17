#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdlib>
using namespace std ;

#define MAXN 107

long long st , en , val ;

long long dp[ MAXN ][ MAXN ][ 2 ][ 2 ] ;

string get_str ( long long x ) {
    string aux ;
    aux.clear ( ) ;
    while ( x != 0 ) {
        aux += ( char( (x%2)+'0') ) ;
        x /= 2 ;
    }
    string ret ;
    ret.clear ( ) ;
    int sz = aux.size ( ) ;
    int i ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret += aux[ i ] ;
    }
    return ret ;
}

long long f ( long long x ) {
    if ( x == 0 ) {
        if ( val == 1 ) { return 1 ; }
        else { return 0 ; }
    }
    string a = get_str ( x ) ;
    int sz = a.size ( ) ;
    int i , j , t , z ;
    for ( i = 0 ; i <= 100 ; i ++ ) {
        for ( j = 0 ; j <= 100 ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                for ( z = 0 ; z < 2 ; z ++ ) {
                    dp[ i ][ j ][ t ][ z ] = 0 ;
                }
            }
        }
    }
    dp[ 0 ][ 0 ][ 1 ][ 0 ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        for ( j = 0 ; j <= val ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                for ( z = 0 ; z < 2 ; z ++ ) {
                    if ( dp[ i ][ j ][ t ][ z ] == 0 ) { continue ; }
                    // add 0
                    int nwj = j ;
                    if ( z == 1 ) { nwj ++ ; }
                    int nwt = t ;
                    if ( a[ i ] == '1' ) { nwt = 0 ; }
                    dp[ i + 1 ][ nwj ][ nwt ][ z ] += dp[ i ][ j ][ t ][ z ] ;
                    // add 1
                    if ( t == 1 && a[ i ] == '0' ) { continue ; }
                    dp[ i + 1 ][ j ][ t ][ 1 ] += dp[ i ][ j ][ t ][ z ] ;
                }
            }
        }
    }
    int add = 0 ;
    if ( val == 1 ) { add = 1 ; }
    return ( dp[ sz ][ val ][ 0 ][ 1 ] + dp[ sz ][ val ][ 1 ][ 1 ] + add ) ;
}

void input ( ) {
    cin >> st >> en >> val ;
}


void solve ( ) {
    cout << f ( en ) - f ( st - 1 ) << "\n" ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
