#include<iostream>
using namespace std;
int main(){
long long n,l;
cin>>n;
cin>>l;
long long a[l],b,d=1,e,cifri=0,f=10,g=1,h;
for(b=0;b<l;b=b+1){
cin>>a[b];
}
for(b=0;b<n;b=b+1){
  for(e=1;d/e>0;e=e*10){cifri++;}
  for(h=0;h<l;h++){
    for(e=0;e<cifri;e=e+1){
       if((d%f)/g==a[h]){
       n=n+1;
       h=l;
       e=cifri;
       }
       f=f*10;
       g=g*10;
    }
    f=10;
    g=1;
  }
d=d+1;
f=10;
g=1;
cifri=0;
}
cout<<n;

return 0;
}
