#include <iostream>
#include <vector>

#define MOD 123456789012345

long long v[1024];
long long din[1024][1024];
long long n;

long long brum(long long q, long long d) {
    if(q >= n)
        return 0;
    if(din[q][d] != 0)
        return din[q][d];
    long long addon = 0;
    for(long long i = q; i < n; i++){
        if(v[q] + d == v[i]) {
            addon = (addon+1) % MOD;
            addon = (addon + brum(i, d)) % MOD;
        }
    }
    return din[q][d] = addon;
}

int main() {
    std::cin >> n;
    long long max = 0;
    for(long long i = 0; i < n; i++) {
        std::cin >> v[i];
        max = std::max(v[i], max);
    }
    long long ans = 0;
    for(long long i = n-1; i >= 0; i--) {
        for(long long j = 1; j < max; j++) {
            ans = (ans + brum(i, j)) % MOD;
        }
    }
    std::cout << ans << std::endl;
}
