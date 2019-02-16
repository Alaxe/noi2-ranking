#include <iostream>
#include <algorithm>
using namespace std;
long long n, k;
unsigned long long resh(long long nok) {
    unsigned long long ans = 1;
    for(unsigned long long i = 2; i <= nok; i ++) {
        long long curr = 0;
        while(nok % i == 0) {
            nok /= i;
            curr ++;
        }
        if(curr > 0) {
            for(; curr > 0; curr -= k) {
                ans *= i;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long nok = 1;
    cin >> n >> k;
    unsigned long long a;
    for(int i = 1; i < n; i ++) {
        cin >> a;
        nok *= (a / (__gcd(a, nok)));
    }
    cout << resh(nok) << "\n";
}
