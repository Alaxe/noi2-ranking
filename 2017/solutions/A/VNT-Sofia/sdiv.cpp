#include <iostream>
#include <string>
using namespace std;
long long ans[10042][1042], n, mod ;
string arr;
int main () {
    cin >> arr;
    cin >> n >> mod;
    ans[0][ (arr[0]-'0')%n ] ++;

    for ( int i = 1 ; i < arr.size() ; i ++ ) {
        int c = (arr[i]-'0')%n;
        ans[i][c] ++;
        if ( ans[i][c] >= mod ) { ans[i][c] -= mod; }

        for ( int j = 0 ; j < n ; j ++ ) {
            ans[i][j] += ans[i-1][j];
            ans[i][ (c+j*10)%n ] += ans[i-1][j];
            if ( ans[i][j] >= mod ) { ans[i][j] -= mod; }
            if ( ans[i][(c+j*10)%n ] >= mod ) { ans[i][(c+j*10)%n ] -= mod; }
        }
    }
    cout << ans[arr.size()-1][0] << "\n";
    return 0;
}
