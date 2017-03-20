#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isLess ( string a, string b ) {
    if ( a.size() > b.size() ) { return 0; }
    if ( a.size() < b.size() ) { return 1; }
    return a < b;
}
string sum ( string a, string b ) {
    string ret;
    reverse ( a.begin(), a.end() );
    reverse ( b.begin(), b.end() );
    while ( a.size() < b.size() ) { a += '0';}
    while ( b.size() < a.size() ) { b += '0';}
    int rem = 0;
    for ( int i = 0 ; i < a.size() ; i ++ ) {
        int c = a[i]-'0' + b[i]-'0' + rem;
        rem = c/10;
        ret += (c%10 + '0' );
    }
    if ( rem ) { ret += (rem+'0'); }
    reverse ( ret.begin(), ret.end() );
    return ret;
}
string subs ( string a, string b ) {
    string ret;
    reverse ( a.begin(), a.end() );
    reverse ( b.begin(), b.end() );
    while ( a.size() < b.size() ) { a += '0';}
    while ( b.size() < a.size() ) { b += '0';}
    int rem = 0;
    for ( int i = 0 ; i < a.size() ; i ++ ) {
        if ( a[i] < b[i] ) {
            int f ;
            for ( int j = i+1 ; j < a.size() ; j ++ ) {
                if ( a[j] != '0' ) { f = j; a[j] --; break; }
            }
            for ( int j = i+1 ; j < f ; j ++ ) { a[j] = '9'; }
            ret += (int)a[i]+10-(int)b[i]+'0';
        }else {
            ret += (int)a[i]-(int)b[i]+'0';
        }
    }
    while (  ret.size() > 1 &&  ret[ ret.size()-1 ] == '0' ) { ret.erase( ret.size()-1 ); }
    reverse ( ret.begin(), ret.end() );
    return ret;
}

int crrArr[242];
string mult ( string a, string b ) {
    string ret;
    for ( int i = 0 ; i < a.size()+b.size()+5 ; i ++ ) {
        crrArr[i] = 0;
    }
    reverse ( a.begin(), a.end() );
    reverse ( b.begin(), b.end() );

    for ( int i = 0 ; i < a.size() ; i ++ ) {
        for ( int j = 0 ; j < b.size() ; j ++ ) {
            crrArr[i+j] += (a[i]-'0')*(int)(b[j]-'0');
        }
    }
    for ( int i = 0 ; i < a.size()+b.size()+5 ; i ++ ) {
        crrArr[i+1] += crrArr[i]/10;
        crrArr[i] %= 10;
        ret += (crrArr[i] + '0' );
    }
    while ( ret.size() > 1 && ret[ ret.size()-1 ] == '0' ) { ret.erase( ret.size()-1 ); }
    reverse ( ret.begin(), ret.end() );
    return ret;
}
string div2 ( string a ) {
    string ret;
    int rem = 0;
    for ( int i = 0 ; i < a.size() ; i ++ ) {
        int c = a[i]-'0';
        ret += ( c+10*rem )/2 +'0';
        rem = (c+10*rem)%2;
    }
    reverse ( ret.begin(), ret.end() );
    while ( ret.size() > 1 && ret[ ret.size()-1 ] == '0' ) { ret.erase( ret.size()-1 ); }
    reverse ( ret.begin(), ret.end() );
    return ret;
}
string get ( string to ) {
    string s = "0", f = to, mid = div2( sum(s, f ) );
    for ( ; sum(s,"1") != f ; mid = div2( sum(s,f) ) ) {
        if ( isLess( mult( mid, sum( mid, "1" ) ) , to ) ) {
            s = mid;
        }else {
            f = mid;
        }
    }
    return s;
}
int main () {

    string n, m;
    cin >> n >> m ;
    m = sum( m, "1" );
    cout << subs( get(m), get(n) ) << "\n" ;
    return 0;
}
