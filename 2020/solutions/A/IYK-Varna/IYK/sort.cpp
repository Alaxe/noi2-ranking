#include <bits/stdc++.h>

const int32_t MAX_N = 1000;
const int32_t MAX_VAL = 10000;
const int32_t INF = 2e9;

struct SegmentTree {
    int32_t data[4 * MAX_N + 5];

    void update(int32_t node, int32_t low, int32_t high, int32_t qInd, int32_t qVal) {
        if(low > qInd || high < qInd) {
            return;
        }
        if(low == qInd && high == qInd) {
            data[node] = qVal;
            return;
        }

        int32_t mid = (low + high) / 2;
        update(2 * node, low, mid, qInd, qVal);
        update(2 * node + 1, mid + 1, high, qInd, qVal);

        data[node] = std::min(data[2 * node], data[2 * node + 1]);
    }

    int32_t query(int32_t node, int32_t low, int32_t high, int32_t qLow, int32_t qHigh) {
        if(low > qHigh || high < qLow) {
            return INF;
        }
        if(low >= qLow && high <= qHigh) {
            return data[node];
        }

        int32_t mid = (low + high) / 2;
        return std::min(query(2 * node, low, mid, qLow, qHigh), query(2 * node + 1, mid + 1, high, qLow, qHigh));
    }
};

int32_t n, m, a[MAX_N + 5], vals[MAX_N + 5], indOf[MAX_VAL + 5], dp[MAX_N + 5][MAX_N + 5];
SegmentTree segTree;

void compute_dp() {
    for(int32_t i = n - 1; i >= 0; i--) {
        for(int32_t j = 0; j < m; j++) {
            if(i == n - 1) {
                if(vals[j] > a[i]) {
                    dp[i][j] = abs(a[i] - vals[j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {
                if(indOf[a[i]] <= j) {
                    dp[i][j] = dp[i + 1][j] + abs(a[i] - vals[j]);
                }
                else {
                    dp[i][j] = a[i] + segTree.query(1, 1, m, j + 1, indOf[a[i]] + 1);
                }
            }
        }

        for(int32_t j = 0; j < m; j++) {
            segTree.update(1, 1, m, j + 1, dp[i][j] - vals[j]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    std::set< int32_t > s;
    s.insert(0);
    for(int32_t i = 0; i < n; i++) {
        std::cin >> a[i];
        s.insert(a[i]);
    }

    int32_t ind = 0;
    for(auto &x : s) {
        indOf[x] = ind;
        vals[ind] = x;
        ind++;
    }

    m = ind;
    compute_dp();

    std::cout << dp[0][0] << '\n';
}
