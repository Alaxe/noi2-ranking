#include <iostream>
using namespace std;

int main () {
    long long n, i, broi1=0, broi2=2;
    cin >> n;
    long long A[n], B[n];
    for (i=0; i < n; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    i=-1;
    while (i < n) {
        for (i=i+1, broi1=1; i < n-1; i++) {
            if ((A[i] >= A[i+1] and B[i] >= B[i+1]) or (B[i] >= A[i+1] and A[i] >= B[i+1])) {broi1++;}
            else {break;}
        }
        if (broi1>broi2) {broi2=broi1;}
    }
    i=n;
    while (i >= 0) {
        for (i=i-1, broi1=1; i > 0; i--) {
            if ((A[i] >= A[i-1] and B[i] >= B[i-1]) or (B[i] >= A[i-1] and A[i] >= B[i-1])) {broi1++;}
            else {break;}
        }
        if (broi1>broi2) {broi2=broi1;}
    }
    cout << broi2 << endl;

return 0;
}

