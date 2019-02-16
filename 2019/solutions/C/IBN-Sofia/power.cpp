#include <iostream>

using namespace std;

int primes[13] = {2,3,5,7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int pows[13];
int n, a, k;
int power (int a, int b) {
    int proizvedenie = 1;
    for (int i = 0; i < b; ++ i)
        proizvedenie *= a;
    return proizvedenie;
}

unsigned long long pow (int a, int b) {
    unsigned long long proizvedenie = 1;
    for (int i = 0; i < b; ++ i)
        proizvedenie *= (unsigned long long)a;
    return proizvedenie;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 0; j < 13; ++j) {
            for (int k = 1; k < 6; ++k) {
                if (a%power(primes[j], k)==0) {
                    pows[j] = max(pows[j], k);
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        pows[i] = (pows[i]+k-1)/k;
    }
    unsigned long long ans = 1;
    for (int i = 0; i < 13; ++i) {
        ans *= pow(primes[i], pows[i]);
    }
    cout << ans << "\n";
    return 0;
}
