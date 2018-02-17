#include <iostream>
#include <string>
using namespace std;

string a;
int mem[128][128], mod = 1000000007;

int solve ( int l, int r ) {
    if ( l > r ) { return 1; }
    if ( mem[l][r] ) { return mem[l][r]; }

    int ret = 1;
    for ( int i = l ; i <= r ; i ++ ) {
        for ( int j = i ; j <= r ; j ++ ) {

            if ( a[i] == a[j] ) {
                ret += solve( i+1, j-1 );
                if ( ret >= mod ) { ret -= mod; }
            }


        }
    }

    mem[l][r] = ret;
    return ret;

}

int main () {

    cin >> a;
    cout << ( solve ( 0, a.size()-1 )-1 + mod )%mod << "\n";

    return 0;
}
