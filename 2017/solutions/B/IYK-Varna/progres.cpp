#include <iostream>
#define endl '\n'
#define Int long long
using namespace std;

const int MAX_N = 1005, MAX_D = 1005;
const Int MOD = 123456789012345LL;

Int n, a[MAX_N], dp[MAX_N], sums[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    Int ans = 0;
    for(int i = 1; i < MAX_D; i++) {
        for(int j = 0; j < MAX_N; j++) {
            dp[j] = 1;
            sums[j] = 0;
        }

        for(int j = 0; j < n; j++) {
            if(a[j] - i > 0) {
                dp[j] = (dp[j] + sums[a[j] - i]) % MOD;
            }

            sums[a[j]] = (sums[a[j]] + dp[j]) % MOD;
        }

        for(int j = 0; j < n; j++) {
            if(dp[j] == 0) {
                ans = (ans + MOD - 1) % MOD;
            }
            else {
                ans = (ans + dp[j] - 1) % MOD;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
