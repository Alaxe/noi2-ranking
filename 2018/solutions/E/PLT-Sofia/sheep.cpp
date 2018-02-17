#include<iostream>
using namespace std;
int main () {
long long n,L,m,p,o,r,x;
cin>>n>>L;
x=10-n;
if(L==1){
cin>>p;
for(r=1;r<=n;r++){
        while(n%100/10==p and n%10>=p){
            p=p+11;
            n=n-22;
        }

        while(n%100/10==p){
            p=p+10;
            n=n-20;
        }
        while(n%10>=p){
            p++;
            n=n-2;
}
}
cout<<p*2+x;

}
if(L==2){
cin>>p>>m;
}if(L==3){
    cin>>m>>p>>o;
}
return 0;
}
