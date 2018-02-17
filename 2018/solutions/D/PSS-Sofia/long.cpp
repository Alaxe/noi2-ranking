#include<iostream>
using namespace std;
int main (){
long long a=0,n,k,s=1;
cin>>n>>k;
while(n>1){
    n=n-1;
    s=s*10;
}
while(a==0){
    for(long long b=s/k;b<=(s*10)/k;b++){
        if(k*b>=s && k*b<s*10 && a==0){
            a=1;
            cout<<k*b;
        }
    }
}
return 0;}
