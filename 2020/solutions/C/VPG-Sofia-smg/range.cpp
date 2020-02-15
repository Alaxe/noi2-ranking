#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
const int MAXN=1e5+10;
int a[MAXN], n;
int findl(int x) {
    int l, r, mid;
    l=0; r=n-1;
    while (l<=r) {
        mid=(l+r)/2;
        if (a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int findr(int x) {
    int l, r, mid;
    l=0; r=n-1;
    while (l<=r) {
        mid=(l+r)/2;
        if (a[mid]<=x) l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int q, l, r, l1, r1;
    cin >> q;
    for (int i=0;i<q;i++) {
        cin >> l >> r;
        l1=findl(l);
        r1=findr(r);
        cout << r1-l1+1 << endl;
    }
    return 0;
}
/**
6
9 1 3 10 3 4
6
1 3
1 1
9 10
1 4
9 12
15 20
**/
