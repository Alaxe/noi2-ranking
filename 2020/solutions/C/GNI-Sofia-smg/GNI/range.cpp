#include <bits/stdc++.h>
using namespace std;
    long long n, m, A[100000];
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    long long i, j, k, a, b, l, r, p;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A, A+n);
    cin >> m;
    for (i=0; i<m; i++){
        cin >> a >> b;
        l=0;
        r=n-1;
        while (r-l>1){
            p=(r-l)/2+l;
            if (A[p]<a) {
                l=p;
            }
        else {
                r=p;
        }
        }
        if (A[l]>=a){
            j=l;
        }else {
        if (A[l]<a and A[l+1]>=a){
            j=l+1;
        }
        else {
        if (A[r]<=a){
            j=r;
        }
        }
        }
        l=0;
        r=n-1;
        while (r-l>1){
            p=(r-l)/2+l;
            if (A[p]<=b) {
                l=p;
            }
        else {
                r=p;
        }
        }
        if (A[l]==b and A[l+1]>b){
            k=l;
        }
        if (A[l]<b and A[l+1]>=b){
            k=l;
        }
        if (A[r]<=b){
            k=r;
        }
        if (A[0]>b or A[n-1]<a) {
            cout << 0 << endl;
        }
        else {
            cout << k-j+1 << endl;
        }
    }
    return 0;
}
