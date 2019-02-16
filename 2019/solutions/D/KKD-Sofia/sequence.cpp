#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector< pair<long long, long long> > dp;

int main() {
    cin >> n >> k;
    dp.push_back(make_pair(0, -1));
    for (int m = 1; m < n; ++ m) {
        dp.push_back(make_pair(dp.back().first + dp.back().second + 2,
                               dp.back().second + 2));
    }
    if (k == 1) {
        cout << dp.back().first + n << endl;
    } else {
        for (int m = 0; m < k / 2; ++ m) {
            dp.push_back(make_pair(dp.back().first + dp.back().second + 2,
                               dp.back().second + 2));
        }
        if (k % 2 == 0) {
            cout << dp.back().first + n << endl;
        } else {
            cout << dp.back().first + n + (dp.size() - n) + (dp.size() - n - 1) + 1 << endl;
        }
    }
    return 0;
}
