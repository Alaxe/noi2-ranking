#include<iostream>
#define endl '\n'
using namespace std;
int a[210];
bool dp[210][210][210];
int main() {
    int n, W1, W2;
    cin >> n >> W1 >> W2;
    for (int i = 1; i < n+1; ++i) {
        cin >> a[i];
    }
    dp[0][0][0] = true;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 0; j <= W1; ++j) {
            for (int k = 0; k <= W2; ++k) {
                if (dp[i-1][j][k]){
                    if(j+a[i]<=W1)dp[i][j+a[i]][k] = true/*,cout << "test1 " << i << " " << j << " " << k << " "*/;
                    if(k+a[i]<=W2)dp[i][j][k+a[i]] = true/*,cout << "test2 "<< i << " " << j << " " << k << " "*/;
                    dp[i][j][k] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= W1; ++i) {
        for (int j = 0; j <= W2; ++j) {
            if (dp[n][i][j]) {
                ans = max(ans, i+j);

            }
        }
    }
    cout << ans << endl;
    return 0;
}
