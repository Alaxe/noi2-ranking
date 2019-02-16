#include <iostream>
using namespace std;
#define endl '\n'
unsigned long long primes[12]={2,3,5,7,11,13,17,23,29,31,37,41};
int st[12];
unsigned long long NOD(unsigned long long a, unsigned long long b) {
    if (b==0) return a;
    return NOD(b,a%b);
}
unsigned long long NOK(unsigned long long a, unsigned long long b) {
    return a/NOD(a,b)*b;
}
unsigned long long stepen(unsigned long long a, int b) {
    unsigned long long ans=1;
    for (int i=0;i<b;i++) ans*=a;
    return ans;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long n, k, a, nok=1;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> a;
        nok=NOK(nok,a);
    }
    int br=0;
    while (nok>1) {
        while (nok>1 and nok%primes[br]==0) {
            st[br]++;
            nok/=primes[br];
        }
        br++;
    }
    unsigned long long ans=1;
    for (int i=0;i<12;i++) {
        ///cout << st[i] << ' ' << primes[i] << endl;
        if (st[i]>0) {
            if (st[i]<=k) ans*=primes[i];
            else {
                if (st[i]%k==0) ans*=stepen(primes[i],st[i]/k);
                else ans*=stepen(primes[i],st[i]/k+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
