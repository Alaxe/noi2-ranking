#include<iostream>
using namespace std;
int main() {
long long int m,k,i,sbor=0,blizo=100000,g,br=0,r=0;
cin>>m>>k;
for(i=1;i<=100000;i++){
cin>>g;
if(br>=200)break;
br+=1;
if(g<m && (m-g)<=blizo || g>m && (g-m)<=blizo || g==m){
  if(g<m)blizo=m-g;
  if(g>m)blizo=g-m;
r=br;
}
if(g%2==0)sbor+=g;
if(sbor>=k)break;
}
cout<<r<<" "<<sbor<<endl;
return 0;
}
