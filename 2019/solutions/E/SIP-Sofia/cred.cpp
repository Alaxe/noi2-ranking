#include <iostream>
using namespace std;
int main(){
long long n,m,l=0,i,h=0;
cin>>n>>m;
while(n<m){
    l=0;
    for(i=1;n/i!=0;i=i*10){
        l++;
    }
    long long c[l],b;
    b=0;
    for(i=1;b!=l;i=i*10){
        c[b]=(n/i)%10;
        b++;
    }
    for(i=0;i<l;i++){
        n=n+c[i];
    }
    h++;
}
cout<<h;
return 0;
}
