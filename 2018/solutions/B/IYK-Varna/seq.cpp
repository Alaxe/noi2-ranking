#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAX_N = 275;
const int MAX_M = 275;

bool isCalculated[MAX_N][MAX_M];
int n, m;
ll dp[MAX_N][MAX_M];

ll ComputeDp(int sum, int lastNum) {
    if(sum > n) {
        return 0ll;
    }
    else if(sum == n) {
        return 1ll;
    }
    else if(isCalculated[sum][lastNum]) {
        return dp[sum][lastNum];
    }

    ll currAns = 0ll;
    for(int i = 1; i <= lastNum; i++) {
        currAns += 1ll * ComputeDp(sum + i, i);
    }

    isCalculated[sum][lastNum] = true;
    dp[sum][lastNum] = currAns;
    return currAns;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cout << ComputeDp(0, m) << endl;
    return 0;
}
