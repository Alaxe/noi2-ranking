#include<bits/stdc++.h>
using namespace std;

int64_t k, m, n, a[61][61], ans;

int main(){
    cin >> k >> m >> n;
    for(int i = 0; i < m; i ++){
        a[1][i] = 1;
    }
    for(int i = 2; i <= n; i ++){
        for(int j = m - 1; j >= 1; j --){
            if(j - k >= 1 && j - k < m){
                a[i][j] += a[i - 1][j - k];
            }
            if(j + k >= 1 && j + k < m){
                a[i][j] += a[i - 1][j + k];
            }
        }
    }
    for(int i = 0; i < m; i ++){
        ans += a[n][i];
    }
    cout << ans << endl;
}
