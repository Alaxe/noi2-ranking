#include <iostream>
using namespace std;

int main () {
    long long n, i, j, k, a, A[6], m;
    cin >> n;

    for (i=n-n%11; i>0; i=i-11) {
        for (j=n-1; j>i-11; j--) {
            a=i*j;
            for (k=0; a!=0; k++) {
                A[k]=a%10;
                a=a/10;
            }
            k--;
            for (m=0; m<k; k--, m++) {
                if (A[m]!=A[k]) {break;}
            }
            if (m>=k) {
                if (i<j) {swap(i,j);}
                cout << j << " " << i << endl;
                cout << i*j << endl;
                return 0;
            }
        }
    }

return 0;
}


