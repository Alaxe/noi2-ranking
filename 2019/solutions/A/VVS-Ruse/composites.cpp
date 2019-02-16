#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    int cnt = 0;
    while(n) {
        n /= 10;
        cnt++;
    }
    for(int i = 0; i < cnt; ++i) cout << 9;
    cout << 2 << endl;
    
    return 0;
}
/*
    for(int i = 2; i <= 100000; ++i) {
        if(done[i]) continue;
        done[i] = 1;
        if(i > 2) prime.push_back(i);
        for(int j = i + i; j <= 100000; j += i) {
            done[j] = 1;
        }
    }
    assert(prime[0] == 3);
    for(int n = 99997; n <= 99999; ++n) {
        long long x;
        x = 999993;
        for(; x >= n; x --) {
            bool good = 1;
            int cnt = 0;
            for(int i = 0; i < (int)prime.size(); ++i) {
                long long curr = 1LL * prime[i] * prime[i] + x;
                //cout << curr << endl;
                bool fl = 0;
                for(int j = 0; j < (int)prime.size() && curr >= prime[j]; ++j) {
                    if(curr % prime[j] == 0 && curr != prime[j]) {
                        fl = 1;
                        cnt++;
                        if(cnt < 10) cout << "ha " << prime[j] << endl;
                        break;
                    }
                }
                if(!fl) {good = 0; break;}
            }
            if(good) {cout << n << " lel " << x << endl; break;}
        }
    }
    */