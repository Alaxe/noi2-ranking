
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 210;
bool dp[MAX_N][MAX_N][MAX_N];
ll n, w1, w2;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> w1 >> w2;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    for(int i = 0; i < MAX_N; i ++) {
        for(int j = 0; j < MAX_N; j ++) {
            for(int k = 0; k < MAX_N; k ++) {
                dp[i][j][k] = false;
            }
        }
    }
    dp[0][0][0] = true;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= w1; j ++) {
            for(int k = 0; k <= w2; k ++) {
                if(!dp[i][j][k]) {continue;}
                dp[i + 1][j][k] = true;
                if(j + arr[i] <= w1) {dp[i + 1][j + arr[i]][k] = true;}
                if(k + arr[i] <= w2) {dp[i + 1][j][k + arr[i]] = true;}
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= w1; i ++) {for(int j = 0; j <= w2; j ++) {if(dp[n][i][j]) {ans = max(ans, i + j);}}}
    cout << ans << endl;
    return 0;
}
