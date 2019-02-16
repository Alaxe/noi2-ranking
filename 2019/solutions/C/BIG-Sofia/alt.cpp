#include<iostream>
using namespace std;
unsigned long long n, m, k;
unsigned long long dp[64][64], otg;
int main(){
    cin >> k >> m >> n;
    for(unsigned long long i = 1; i < m; i++){
        dp[i][1] = 1;
    }
    for(unsigned long long i = 1; i <= n; i++){
        for(unsigned long long j = 1; j < m; j++){
            if(j > k){
                dp[j - k][i + 1] += dp[j][i];
            }
            if(j + k < m){
                dp[j + k][i + 1] += dp[j][i];
            }
        }
    }
    for(unsigned long long i = 1; i < m; i++){
        otg += dp[i][n];
    }

    cout << otg << endl;

return 0;
}
/// 21 826 967 349 178 000
