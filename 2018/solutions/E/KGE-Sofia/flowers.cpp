#include<iostream>
using namespace std;
int main (){
long long n,q,naigolqmo,k=0;
cin>>n;
long long s[n];
for(int a=0;a<n;a++){
 cin>>s[a];
 if(a==0){
  naigolqmo=s[a];
 }
if(a[s]>naigolqmo){
naigolqmo=a[s];
}
}
cin>>q;
for(int b=0;b<n;b++){
k=(naigolqmo-s[b])*q+k;
}
cout<<k;
return 0;
}
