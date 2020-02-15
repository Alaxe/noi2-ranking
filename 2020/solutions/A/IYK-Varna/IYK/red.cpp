#include <bits/stdc++.h>

const int32_t MAX_N = 1e5;
const int32_t MAX_M = 1e5;
const int32_t MAX_VAL = 2e6;

int32_t w, k, n, m, a[MAX_N + 5], b[MAX_M + 5];
int32_t cntA[MAX_VAL + 5], cntB[MAX_VAL + 5];

int64_t solve2() {
    int32_t cnt = 0;
    for(int32_t i = 0; i < n; i++) {
        if(i == 0) {
            cnt++;
        }
        else {
            if(a[i] == a[i - 1]) {
                cnt++;
            }
            else {
                if(cnt >= k) {
                    cntA[a[i - 1]] += cnt - k + 1;
                }
                cnt = 1;
            }
        }
    }
    if(cnt >= k) {
        cntA[a[n - 1]] += cnt - k + 1;
    }

    cnt = 0;
    for(int32_t i = 0; i < m; i++) {
        if(i == 0) {
            cnt++;
        }
        else {
            if(b[i] == b[i - 1]) {
                cnt++;
            }
            else {
                if(cnt >= k) {
                    cntB[b[i - 1]] += cnt - k + 1;
                }
                cnt = 1;
            }
        }
    }
    if(cnt >= k) {
        cntB[b[m - 1]] += cnt - k + 1;
    }

    int64_t ans = 0;
    for(int32_t i = 0; i <= MAX_VAL; i++) {
        ans += (int64_t) cntA[i] * cntB[i];
    }

    return ans;
}

int64_t solve1() {
    int32_t ans = 0;
    for(int32_t i = 0; i < n; i++) {
        bool ok = true;
        for(int32_t j = 1; j < k; j++) {
            if(a[i + j - 1] >= a[i + j]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            int32_t matched = 0;
            for(int32_t j = 0; j < m; j++) {
                if(matched == k) {
                    ans++;
                    matched = 0;
                }
                if(a[i + matched] == b[j]) {
                    matched++;
                }
                else {
                    matched = 0;
                    if(a[i + matched] == b[j]) {
                        matched++;
                    }
                }
            }

            if(matched == k) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> w >> k;

    std::cin >> n;
    for(int32_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cin >> m;
    for(int32_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    if(k > n || k > m) {
        std::cout << 0 << '\n';
        return 0;
    }

    if(w == 1) {
        std::cout << solve1() << '\n';
    }
    else {
        std::cout << solve2() << '\n';
    }
}
