#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std ;

vector < int > st , en ;

vector < int > parse ( string s ) {
    int i , sz ;
    sz = s.size ( ) ;
    vector < int > ret ;
    for ( i = 0 ; i < sz ; i ++ ) {
        ret.push_back ( ( s[ i ] - '0') ) ;
    }
    return ret ;
}

vector < int > rev ( vector < int > v ) {
    int i , sz ;
    sz = v.size ( ) ;
    vector < int > ret ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret.push_back ( v[ i ] ) ;
    }
    return ret ;
}

bool cmp ( vector < int > v1 , vector < int > v2 ) {
    int sz1 = v1.size ( ) ;
    int sz2 = v2.size ( ) ;
    if ( sz1 < sz2 ) { return true ; }
    if ( sz1 > sz2 ) { return false ; }
    int i ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        if ( v1[ i ] < v2[ i ] ) { return true ; }
        if ( v1[ i ] > v2[ i ] ) { return false ; }
    }
    return true ;
}

vector < int > add ( vector < int > v1 , vector < int > v2 ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int sz1 = v1.size ( ) ;
    int sz2 = v2.size ( ) ;
    v1 = rev ( v1 ) ;
    v2 = rev ( v2 ) ;
    while ( sz1 < sz2 ) {
        v1.push_back ( 0 ) ;
        sz1 ++ ;
    }
    while ( sz2 < sz1 ) {
        v2.push_back ( 0 ) ;
        sz2 ++ ;
    }
    int i ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        ret.push_back ( v1[ i ] + v2[ i ] ) ;
    }
    int pr = 0 ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        ret[ i ] += pr ;
        pr = ( ret[ i ] / 10 ) ;
        ret[ i ] %= 10 ;
    }
    while ( pr != 0 ) {
        ret.push_back ( pr % 10 ) ;
        pr /= 10 ;
    }
    ret = rev ( ret ) ;
    return ret ;
}

vector < int > subtract ( vector < int > v1 , vector < int > v2 ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int sz1 = v1.size ( ) ;
    int sz2 = v2.size ( ) ;
    if ( cmp ( v1 , v2 ) == true ) { swap ( v1 , v2 ) ; }
    v1 = rev ( v1 ) ;
    v2 = rev ( v2 ) ;
    while ( sz1 < sz2 ) {
        v1.push_back ( 0 ) ;
        sz1 ++ ;
    }
    while ( sz2 < sz1 ) {
        v2.push_back ( 0 ) ;
        sz2 ++ ;
    }
    int i ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        int val = ( v1[ i ] - v2[ i ] ) ;
        while ( val < 0 ) {
            val += 10 ;
            v1[ i + 1 ] -- ;
        }
        ret.push_back ( val ) ;
    }

    for ( i = sz1 - 1 ; i >= 0 ; i -- ) {
        if ( ret[ i ] != 0 ) { break ; }
        ret.pop_back ( ) ;
    }
    ret = rev ( ret ) ;
    return ret ;
}

vector < int > mul_digit ( vector < int > v1 , int x ) {
    vector < int > ret ;
    int i ;
    int sz = v1.size ( ) ;
    v1 = rev ( v1 ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        ret.push_back ( v1[ i ] * x ) ;
    }
    int pr = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        ret[ i ] += pr ;
        pr = ( ret[ i ] / 10 ) ;
        ret[ i ] %= 10 ;
    }
    while ( pr != 0 ) {
        ret.push_back ( ( pr % 10 ) ) ;
        pr /= 10 ;
    }
    ret = rev ( ret ) ;
    return ret ;
}

vector < int > mul ( vector < int > v1 , vector < int > v2 ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int i , j ;
    int sz1 = v1.size ( ) ;
    int sz2 = v2.size ( ) ;
    for ( i = sz2 - 1 ; i >= 0 ; i -- ) {
        vector < int > aux = mul_digit ( v1 , v2[ i ] ) ;
        for ( j = i + 1 ; j < sz2 ; j ++ ) { aux.push_back ( 0 ) ; }
        ret = add ( ret , aux ) ;
    }
    return ret ;
}

vector < int > div ( vector < int > v1 , int x ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int i ;
    int sz = v1.size ( ) ;
    int cur = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        cur = ( cur * 10 + v1[ i ] ) ;
        if ( cur < x ) {
            if ( ret.size ( ) != 0 ) { ret.push_back ( 0 ) ; }
        }
        else {
            ret.push_back ( ( cur / x ) ) ;
            cur %= x ;
        }
    }
    return ret ;
}

void print ( vector < int > v ) {
    int i ;
    int sz = v.size ( ) ;
    if ( sz == 0 ) { cout << "0" ; }
    for ( i = 0 ; i < sz ; i ++ ) {
        cout << v[ i ] ;
    }
    cout << "\n" ;
}

vector < int > f ( vector < int > lim ) {
    vector < int > l , r , mid ;
    l.clear ( ) ;
    r.clear ( ) ;
    l.push_back ( 1 ) ;
    r.push_back ( 1 ) ;
    int i ;
    int sz = lim.size ( ) ;
    for ( i = 1 ; i <= ( ( sz / 2 ) + 2 ) ; i ++ ) {
        r.push_back ( 0 ) ;
    }
    while ( 1 ) {
        vector < int > u = subtract ( r , l ) ;
        if ( u.size ( ) == 1 ) { break ; }
        mid = add ( l , r ) ;
        mid = div ( mid , 2 ) ;
        u.clear ( ) ;
        u.push_back ( 1 ) ;
        u = add ( u , mid ) ;
        u = mul ( mid , u ) ;
        if ( cmp ( u , lim ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( 1 ) {
        vector < int > u ;
        u.clear ( ) ;
        u.push_back ( 1 ) ;
        u = add ( r , u ) ;
        u = mul ( r , u ) ;
        if ( cmp ( u , lim ) == true ) { break ; }
        u.clear ( ) ;
        u.push_back ( 1 ) ;
        r = subtract ( r , u ) ;
    }
    return r ;
}

void input ( ) {
    string foo1 , foo2 ;
    cin >> foo1 >> foo2 ;
    st = parse ( foo1 ) ;
    en = parse ( foo2 ) ;
}

void solve ( ) {
    vector < int > u ;
    u.clear ( ) ;
    u.push_back ( 1 ) ;
    vector < int > arg = subtract ( st , u ) ;
    vector < int > v1 = f ( arg ) ;
    vector < int > v2 = f ( en ) ;
    vector < int > ans = subtract ( v2 , v1 ) ;
    print ( ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
