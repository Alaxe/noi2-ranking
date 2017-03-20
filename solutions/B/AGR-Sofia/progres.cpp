#include<iostream>
using namespace std;
long long a[1002][1002];
long long n;
long long num[1002];
long long sr[1002];
long long mn = 1002, mx = 0;
long long ost = 123456789012345, ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(long long i = 0; i < n; i ++) {
            cin >> num[i];
            mn = min(mn, num[i]);
            mx = max(mx, num[i]);
    }
    for(long long i = n - 1; i >= 0; i --) {
        sr[num[i]] ++;
        for(long long j = 1; num[i] + j  <= mx && j < mx - mn + 1; j ++) {
            a[num[i]][j] = (a[num[i]][j] % ost + sr[num[i] + j] % ost + a[num[i] + j][j] % ost) % ost;
            ans =  (ans% ost + sr[num[i] + j] % ost + a[num[i] + j][j] % ost) % ost;
        }
    }
    cout << ans;
}
/*
3
1 2 3
*/
/*
6
1 9 1 9 2 3
*/

/*
8
1 8 2 6 3 10 2 3
*/
