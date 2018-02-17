#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std ;

int b ;
vector < int > init ;


vector < int > v ;

vector < int > rev ( vector < int > x ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int sz = x.size ( ) ;
    int i ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret.push_back ( x[ i ] ) ;
    }
    return ret ;
}

vector < int > mul ( vector < int > x , int val ) {
    int i ;
    int sz = x.size ( ) ;
    x = rev ( x ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        x[ i ] *= val ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        int pr = ( x[ i ] / b ) ;
        x[ i ] %= b ;
        if ( pr != 0 ) {
            if ( i == ( sz - 1 ) ) {
                x.push_back ( 0 ) ;
                sz ++ ;
            }
            x[ i + 1 ] += pr ;
        }
    }
    x = rev ( x ) ;
    return x ;
}

vector < int > sub1 ( vector < int > x ) {
    int i ;
    x = rev ( x ) ;
    int sz = x.size ( ) ;
    x[ 0 ] -- ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( x[ i ] < 0 ) {
            x[ i ] += b ;
            x[ i + 1 ] -- ;
        }
    }
    while ( x[ sz - 1 ] == 0 ) {
        x.pop_back ( ) ;
        sz -- ;
    }
    if ( sz == 0 ) { x.push_back ( 0 ) ; }
    x = rev ( x ) ;
    return x ;
}

vector < int > add ( vector < int > x , vector < int > y ) {
    x = rev ( x ) ;
    y = rev ( y ) ;
    int sz1 = x.size ( ) ;
    int sz2 = y.size ( ) ;
    while ( sz1 < sz2 ) {
        x.push_back ( 0 ) ;
        sz1 ++ ;
    }
    while ( sz1 > sz2 ) {
        y.push_back ( 0 ) ;
        sz2 ++ ;
    }
    vector < int > ret ;
    int pr = 0 ;
    int i ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        int c = ( x[ i ] + y[ i ] + pr ) ;
        ret.push_back ( ( c % b ) ) ;
        pr = ( c / b ) ;
    }
    while ( pr != 0 ) {
        ret.push_back ( ( pr % b ) ) ;
        pr /= b ;
    }
    ret = rev ( ret ) ;
    return ret ;
}
int get_mod ( vector < int > x , int mod ) {
    int i ;
    int sz = x.size ( ) ;
    int ret = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        ret = ( ret * b + x[ i ] ) % mod ;
    }
    return ret ;
}
vector < int > div ( vector < int > x , int mod ) {
    int i ;
    int sz = x.size ( ) ;
    vector < int > ret ;
    ret.clear ( ) ;
    int val = 0 ;
    bool fl = false ;
    for ( i = 0 ; i < sz ; i ++ ) {
        val = ( val * b + x[ i ] ) ;
        if ( val < mod ) {
            if ( fl == true ) { ret.push_back ( 0 ) ; }
        }
        else {
            fl = true ;
            ret.push_back ( ( val / mod ) ) ;
            val %= mod ;
        }
    }

    return ret ;
}

bool check ( int dig , int len ) {
    v.clear ( ) ;
    v.push_back ( 1 ) ;
    int i ;
    for ( i = 1 ; i <= len ; i ++ ) {
        v = mul ( v , b ) ;
    }
    v = sub1 ( v ) ;
    v = mul ( v , dig ) ;
    v = add ( v , init ) ;
    int aux = get_mod ( v , ( b - 1 ) ) ;
    if ( aux != 0 ) { return false ; }
    v = div ( v , ( b - 1 ) ) ;
    if ( v.size ( ) != len ) { return false ; }
    if ( v[ 0 ] != dig ) { return false ; }
    return true ;
}

void input ( ) {
    string s ;
    cin >> s ;
    int i ;
    int sz = s.size ( ) ;
    init.clear ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( s[ i ] >= '0' && s[ i ] <= '9' ) {
            init.push_back ( ( s[ i ] - '0' ) ) ;
        }
        else {
            init.push_back ( 10 + ( s[ i ] - 'A' ) ) ;
        }
    }
}

void print ( ) {
    int sz = v.size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ i ] >= 0 && v[ i ] <= 9 ) {
            cout << ( char ( '0' + v[ i ] ) ) ;
        }
        else {
            cout << ( char ( 'A' + ( v[ i ] - 10 ) ) ) ;
        }
    }
    cout << "\n" ;
}

void solve ( ) {
    int dig , len ;
    int sz = init.size ( ) ;
    for ( len = sz ; len <= sz + 2 ; len ++ ) {
        for ( dig = 1 ; dig < b ; dig ++ ) {
            if ( check ( dig , len ) == true ) {
                print ( ) ;
                return ;
            }
        }
    }
    cout << "0\n" ;
}

int main ( ) {
    cin >> b ;
    int br = 4 ;
    while ( br != 0 ) {
        br -- ;
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
