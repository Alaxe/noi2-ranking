#include <bits/stdc++.h>
using namespace std;
    long long A[44];
    void kanon(long long a) {
        long long i, m;
        for (i=2; a!=1; i++) {
            m=0;
            while (a%i==0) {
                m++;
                a=a/i;
            }
            A[i]=max(A[i], m);
        }
    }
int main () {
    long long n, k, i, a, br=1;
    cin >> n >> k;
    for (i=0; i<n; i++) {
        cin >> a;
        kanon(a);
    }
    for (i=2; i<44; i++) {
        for (int j=0; j<A[i]/k; j++) {
            br=br*i;
        }
        if (A[i]%k!=0) {
            br*=i;
        }
    }
    cout << br << endl;
return 0;
}

