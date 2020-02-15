#include<iostream>
using namespace std;
int main() {
int n, w1, w2, total=0;
cin>>n>>w1>>w2;
int max1=0, max2=0;
int a[200];
for (int k=0; k<n; k++) {
    cin>>a[k];
    total+=a[k];
}
if (w1+w2<total) {
    cout<<w1+w2;
}
else {
    cout<<total;
}
//:D
return 0;
}
