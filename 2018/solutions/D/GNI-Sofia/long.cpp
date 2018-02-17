#include <iostream>
using namespace std;

int main () {
    long long i, n, k, ost=0;
    cin >> n >> k;
    long long A[n];
    A[0]=1;
    for (i=1; i<n; i++) {
        A[i]=0;
    }
    for (i=0; i<n; i++) {
        ost=(ost*10+A[i])%k;
    }
    if (ost!=0) {
    ost=k-ost;
    }
    for (i=n-1; ost>0; i--) {
        A[i]+=ost%10;
        ost=ost/10;
    }
    for (i=0; i<n; i++) {
        cout << A[i];
    }
    cout << endl;
return 0;
}
