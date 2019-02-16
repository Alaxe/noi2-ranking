#include <iostream>
#include <algorithm>
using namespace std;
int st(long long x, long long y) {
    long long a=1,i;
    for(i=0;i<y;i++) {
        a=a*x;
    }
    return a;
}
int main () {
    long long n,m;
    cin>>n>>m;
    long long a[n],u=1,i;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=n-1;i>=0;i--) {
        if(st(u,m)%a[i]!=0) {
            u=u*a[i];
        }
    }
    cout<<u<<endl;
    return 0;
}
