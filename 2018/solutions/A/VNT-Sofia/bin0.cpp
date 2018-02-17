//Sorry lads, I ain't gay.
#include <iostream>
using namespace std;

long long bitCnt ( long long x ) {
    long long ans = 0;
    for ( int i = 0 ; i < 64 ; i ++ ) {
        if ( (1LL<<i)&x ) { ans++; }
    }
    return ans;
}

long long slow ( long long s, long long t, long long z ) {
    long long ans = 0;
    for ( long long i = s ; i < t ; i ++ ) {
        if ( bitCnt( i ) == z ) { ans ++; }
    }
    return ans;
}
long long mem[64][64];
long long comb ( long long n, long long k ) {
    if ( k < 0 || k > n ) { return 0; }

    if ( n == k || k == 0 ) { return 1; }
    if ( mem[n][k] ) { return mem[n][k]; }
    mem[n][k] = comb( n-1, k-1 ) + comb( n-1, k );
    return mem[n][k];
}

long long solve ( long long s, long long t, long long z ) {
    if ( s == t ) { return 0; }
    if ( z < 0 ) { return 0; }

    if ( s+1 == t ) {
        if ( bitCnt( s ) == z ) { return 1; }
        return 0;
    }

    for ( long long i = 0 ; i < 63 ;i ++ ) {
        if ( s == 0 && t == (1LL<<i) ) { return comb( i, z ); }
    }

    long long st = 62;
    for ( ; (1LL<<st) >= t ; st -- ) {}

    long long ret = 0;
    if(  s < (1LL<<st) && (1LL<<st) < t ) {
        ret += solve( 0, (1LL<<st)-s, st-z ) + solve ( 0, t - (1LL<<st), z-1 );
    }else {
        ret += solve ( s-(1LL<<st), t-(1LL<<st), z-1 );
    }

    return ret;
}

int main () {
    long long s, t, z;
    cin >> s >> t >> z;

    cout << solve ( s, t+1, z ) << "\n";

    return 0;
}
