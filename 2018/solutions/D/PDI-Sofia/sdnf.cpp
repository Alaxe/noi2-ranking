#include<iostream>
using namespace std;
int long long fac( int n){
int long long fact=1;
int a=1;
if(n>1){
for(n;n!=1;n--)
if(n%5!=0)
fact=fact*n;
else if(n%2!=0) a=2*a;
}
 return fact/a;
}
int sum(int long long  n){
int sudi=0;
for(n;n>0;n=n/10){
    sudi=sudi+n%10;
}
return sudi;
}
int main(){
int  a;
cin>>a;
cout<<sum(fac(a));
return 0;
}
