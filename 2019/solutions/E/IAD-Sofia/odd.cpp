#include<iostream>
using namespace std;
int devide(int n){
int i;
int brdel=0;
for(i=1;i<=n/2;i++){
    if(n%i==0){
        brdel++;
    }
}
return brdel+1;
}
int main(){
unsigned long long  a,b;
cin>>a>>b;
int numbers=0;
for(int i=a;i<=b;i++){

    if(devide(i)%2==1)numbers++;
}
cout<<numbers;
}
