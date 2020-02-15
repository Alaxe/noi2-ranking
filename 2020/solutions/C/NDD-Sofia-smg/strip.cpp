#include <iostream>
using namespace std;
int f(int a,int b) {
    long long s=1,c=1;
    for(int i=a;i>=b;i--) {
        s=s*i;
        s=s/c;
        c++;
    }
    return s;
}
int main () {
    long long n,k,p=1;
    cin>>n>>k;
    if (k==1 or k==n) {
    cout<<1<<endl;
    }else {
        long long x=n;
        while (x>1) {
            p=p*2;
            x--;
        }
        for(int i=k;i<=n-1;i++) {
                p=p-f(n-1,n-i);
        }
        for(int i=n-k+1;i<=n-1;i++) {
            p=p-f(n-1,n-i);
        }
        cout<<p<<endl;
    }
    return 0;
}
