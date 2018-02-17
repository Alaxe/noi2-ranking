#include<iostream>
using namespace std;
int main(){
long long n;
cin>>n;
long long a[n],b,c=0,q,naig=0;
for(b=0;b<n;b=b+1){
cin>>a[b];
}
cin>>q;
for(b=0;b<n;b=b+1){
if(a[b]>naig){
naig=a[b];
}
}
for(b=0;b<n;b++){
if(a[b]<naig){
c=c+(naig-a[b])*q;
}
}
cout<<c;
return 0;
}
