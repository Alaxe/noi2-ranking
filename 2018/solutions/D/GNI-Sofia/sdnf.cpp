#include <iostream>
using namespace std;
    int A[100000];
    long long cifri(long long a) {
        long long i=0;
        while (a>0) {i++; a=a/10;}
        return i;
    }
int main () {
    int n, sbor=0, i, pren=0, pren2, j, broi=1;
    cin >> n;
    A[0]=1;
    for (i=2; i<=n; i++) {
        for (j=0; j<broi; j++) {
            pren2=(A[j]*i+pren)/10;
            A[j]=(A[j]*i+pren)%10;
            pren=pren2;
        }
        broi+=cifri(pren2);
        for (j=j; pren2>0; j++) {
            A[j]=pren2%10;
            pren2/=10;
        }
        pren=0;
    }
    for (i=0; i<broi; i++) {
        sbor=sbor+A[i];
    }
    cout << sbor << endl;
return 0;
}
