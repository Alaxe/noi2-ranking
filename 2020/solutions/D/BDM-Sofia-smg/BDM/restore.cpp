#include <iostream>
using namespace std;
int main() {
unsigned int n;
cin>>n;
int b[n];
int a[n];
int mini=n;
int maxi=2;
for (int i=0;i<n;i++) {
    cin>>b[i];
    a[i]=1;
}
for (int j=n-1;j>0;j--) {
    if (b[j]==0) {
        a[j]=a[j]+maxi;
        maxi=a[j];
    }else if (b[j]>0){
        a[j]+=mini+1;
        mini=a[j];
    }
}
for (int h=0;h<n;h++) {
    cout<<a[h]<<" ";
}
}
