#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std ;

int n , k ;

long long ans ;

long long fst , mul , add , mod ;

deque < pair < int , int > > q ;

void input ( ) {
    cin >> n >> k ;
    cin >> fst >> mul >> add >> mod ;
}

void solve ( ) {
    ans = 0 ;
    int i ;
    long long cur = 0 ;
    for ( i = 1 ; i <= n ; i ++ ){
        if ( i == 1 ) { cur = fst ; }
        else { cur = ( cur * mul + add ) % mod ; }
        while ( q.empty( ) == false && q.back( ).first <= cur ) {
            q.pop_back( ) ;
        }
        q.push_back ( make_pair ( cur , i ) ) ;
        while ( q.empty( ) == false && q.front( ).second <= ( i - k ) ) {
            q.pop_front( ) ;
        }
        ans += q.front( ).first ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
