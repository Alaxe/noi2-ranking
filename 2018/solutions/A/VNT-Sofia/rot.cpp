#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int p;
string m, k;

int getDig ( char c ) {
    if ( c >= '0' && c <= '9' ) { return c - '0'; }
    return c - 'A' + 10;
}
char setDig ( int c ) {
    if ( c < 10 ) { return c + '0'; }
    return c-10 + 'A';
}

string divB( string a, int k ) {
    string ans = "";
    int rem = 0;
    bool setD = 0;

    for ( int i = 0 ; i < a.size() ; i ++ ) {
        rem *= p;
        rem += getDig( a[i] );

        setD |= ( (rem/k) != 0 );

        if ( setD ) {
            ans += setDig ( ( rem/k ) );
        }
        rem %= k;
    }

    if ( rem ) { ans = ""; }
    return ans;
}

bool posL ( ) {
    for ( int i = 0 ; i < k.size()-1 ; i ++ ) {
        if ( k[i] < setDig( p-2) ) { return 1; }
        if ( k[i] > setDig( p-2) ) { return 0; }
    }
    if ( k[ k.size()-1 ] == setDig( p-1 ) ) { return 0; }
    return 1;
}
string ans;

string add ( string a, string b ) {
    string ret = "";
    reverse ( a.begin(), a.end() );
    reverse ( b.begin(), b.end() );

    for ( ; a.size() < b.size() ; a += '0' ){}
    for ( ; b.size() < a.size() ; b += '0' ){}

    int rem = 0;
    for ( int i = 0 ; i < a.size() ; i ++ ) {
        rem += getDig( a[i] ) + getDig( b[i] );

        ret += setDig( rem%p );
        rem /= p;
    }
    if ( rem ) {
        ret += setDig( rem );
    }
    reverse ( ret.begin(), ret.end() );
    return ret;
}

void solve () {
    cin >> m;

    k = divB ( m, p-1 );
    if ( k.size() == 0 ) { cout << "0\n"; return; }
    int n = k.size()+1;
    if ( !posL () ) { n ++; }
    ans.clear();

    for ( int i = 0 ; i < n ; i ++ ) {
        ans += '1';
    }
    ans = add ( ans, k );
    cout << ans << "\n";


}
int main () {
    cin >> p;

    solve();
    solve();
    solve();
    solve();

    return 0;
}
