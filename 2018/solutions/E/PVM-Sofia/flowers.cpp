#include<iostream>
using  namespace std;
int main (){
long long n,q,oV=0,ng=0;
long w;
cin>>n;
long long cv[n];
for (w=0;w<n;w++) cin>>cv[w];
cin>>q;
for (w=0;w<n;w++) {
 if (cv[w]>ng) ng=cv[w];
}
for (w=0;w<n;w++) {
 oV=(q*(ng-cv[w]))+oV;
}
cout<<oV;
return 0;
}
