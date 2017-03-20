#include <iostream>
using namespace std;
int main () {
    long long N;
    cin >> N;
    long long a[N],b[N],l[N],bigger[N],c[N],d[N],br=0,f;
    for (long long n=0;n<N;n++) {
        bigger[n]=1;
    }
    for (long long k=0;k<N;k++) {
        cin >> a[k] >> b[k];
        l[k]=a[k]*b[k];
    }
    for (long long m=0;m<N;m++) {
            for (long long o=0;o<N;o++) {
                if (l[o]>bigger[m]) {
                bigger[m]=l[o];
                c[m]=a[o];
                d[m]=b[o];
            }
            }
    }
    for (f=0;f<N;f++) {
        if ((c[f]>=c[f+1] and d[f]>=d[f+1])or (c[f]>=d[f+1] and d[f]>=c[f+1])) {
                if ((c[f]==c[f+1]) or (c[f]==d[f+1]) or (d[f]==d[f+1]) or (d[f]==c[f+1])) {
                 br++;
                }
        }
    }
    cout << br-1 << endl;
    return 0;
}
