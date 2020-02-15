#include <iostream>
using namespace std;
#define endl '\n'
long long dp[51][51];
long long rec(int l, int r) {
    if (dp[l][r]!=-1) return dp[l][r];
    return dp[l][r]=rec(l+1,r)+rec(l,r-1);
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    k--;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) dp[i][j]=-1;
    }
    for (int i=0;i<n;i++) dp[i][i]=0;
    dp[k][k]=1;
    cout << rec(0,n-1) << endl;
    return 0;
}
