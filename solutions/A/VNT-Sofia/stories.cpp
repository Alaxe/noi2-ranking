#include <iostream>
#include <deque>
using namespace std;

deque < pair < long long , long long > > d;
long long n, k, first, add, mul, mod, ans;
int main ( ) {
    cin >> n >> k;
    cin >> first >> mul >> add >> mod;
    for ( int i = 0 ; i < n ; i ++ ) {

        while ( !d.empty() && d.back().first < first ) { d.pop_back(); }
        d.push_back( make_pair( first, i ) ) ;
        while ( d.front().second <= i-k ) { d.pop_front(); }
        ans += d.front().first;
        //cout << d.front().first << " ";
        first = ( first*mul + add )%mod;
    }
    cout << ans << "\n";
    return 0;
}
