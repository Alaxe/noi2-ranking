#include <iostream>
#include <math.h>
using namespace std;
int a[1303];
int b[1303];
int l;
void palindrom() {
    int i=l/2;
    if (l%2==0) i--;
    for (;i>=0;i--) {
        if (a[i]==9) {
            a[i]=a[l-i-1]=0;
        } else {
            a[i]++;
            a[l-i-1]++;
            break;
        }
    }
}
bool bigger() {
    for (int i=0;i<l;i++) {
        if (a[i]>b[i]) return true;
    }
    return false;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i=0;
    char z;
    bool p=true;
    while (cin >> z) {
        a[i]=z-'0';
        if (a[i]!=9) p=false;
        b[i]=a[i];
        i++;
    }
    l=i;
    if (p) {
        a[0]=1;
        a[l]=1;
        for (int i=1;i<l;i++) a[i]=0;
        for (i=0;i<l+1;i++) cout << a[i];
        cout << '\n';
        return 0;
    }
    for (int i=0;i<l/2;i++) {
        if (i>0) a[i]=a[l-i-1]=min(a[i],a[l-i-1]);
        else a[l-i-1]=a[i];
    }
    if (bigger()) {
        for (i=0;i<l;i++) cout << a[i];
        cout << '\n';
        return 0;
    }
    if (l%2==1) {
        if (a[l/2+1]<9) a[l/2+1]++;
        else {
            a[l/2+1]=0;
            palindrom();
        }
    } else palindrom();
    for (i=0;i<l;i++) cout << a[i];
    cout << '\n';
    return 0;
}
