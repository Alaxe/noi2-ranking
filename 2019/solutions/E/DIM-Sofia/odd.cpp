#include<iostream>
using namespace std;
int main(){
long long p=0,a,b,n,pi=0;
cin>>a>>b;

for(n=a;n<=b;n++){
    for(long long i=1;i*i<=n;i++){
        if(i*i==n){
            p++;
        }
    }
}
cout<<p;
return 0;
}
