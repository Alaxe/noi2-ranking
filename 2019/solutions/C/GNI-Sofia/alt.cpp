#include <bits/stdc++.h>
using namespace std;
    long long br=0, n, k, m;
    void mnogosumqk(long long j, long long p) {
        if (p==n) {
            br++;
        }
        else {
        if (j+k<m) {
            mnogosumqk(j+k, p+1);
        }
        if (j-k>0) {
            mnogosumqk(j-k, p+1);
        }
        }
    }
int main () {
    long long i, p;
    cin >> k >> m >> n;
    for (i=1; i<m; i++) {
        p=1;
        mnogosumqk(i, p);
    }
    cout << br << endl;
return 0;
}
