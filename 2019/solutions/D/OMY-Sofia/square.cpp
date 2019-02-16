#include<iostream>
#include<cmath>
using namespace std;
long long NOD(long long a,long long b){
for(long long i=b;;i+=b){
   if(i%a==0){
      return i;
   }
}
}
int main () {
long long n,j;
cin>>n;
long long a[n],nd;
cin>>a[0];
nd=a[0];
for(long long i=1;i<n;i++){
cin>>a[i];
   nd =NOD(nd,a[i]);
}
for(long long i=nd;;nd=i+nd){
  if(int(sqrt(nd))*int(sqrt(nd))==nd){
 cout<<sqrt(nd);
cout<<endl;
         return 0;
  }
      }
return 0;
}
