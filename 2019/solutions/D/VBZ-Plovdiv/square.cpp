#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,nod,pr;
cin>>n;
cin>>nod;
for(long long i=1;i<=n-1;i++){
long long ch;
cin>>ch;
pr=nod*ch;
while(ch){
    long long r=ch;
    ch=nod%ch;
    nod=r;
}
nod=pr/nod;
}
long long nok=nod;
long long key=0,d=0;
while(true){
key++;
long long a=key*nok;
double prom=sqrt(a);
d=prom/1;
if(prom==d)break;
}
cout<<d<<endl;
return 0;
}
