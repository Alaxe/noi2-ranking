//ready
#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,m11;
long long binaryl(long long x) {
long long l=0,r=n-1,m=(l+r)/2;
while (l<r) {
    m=(l+r)/2;
        if (a[m]<x) l=m+1;
        else r=m;
}
return l;
}
long long binaryr(long long x) {
long long l=0,r=n-1,m=(l+r)/2;
while (l<r-1) {
    m=(l+r)/2;
        if (a[m]>x) r=m-1;
        else l=m;
}
return r;
}
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
cin>>n;
for (int q=0;q<n;q++) cin>>a[q];
sort(a,a+n);
cin>>m11;
long long c,b;
for (int q=0;q<m11;q++) {
    cin>>c>>b;
    if (c>a[n-1]) cout<<"0\n";
    else {
        if (b<a[0]) cout<<"0\n";
        else {
           long long c1=binaryl(c),b1=binaryr(b);
           if (a[c1]<c) c1++;
           if (a[b1]>b) b1--;
           cout<<b1-c1+1<<"\n";
        }
    }
}
return 0;
}
