#include<iostream>
using namespace std;
int main(){
long long n,k,broiCifri=0,a,b;
cin>>n>>k;
a=k;
b=k;
while(broiCifri<n){
    broiCifri=0;
    while(k>=1){
        k=k/10;
        broiCifri++;
    }
    k=b;
    k=k+a;
    b=k;
}
k=k-a;
if(broiCifri==n){
    cout<<k;
}else{
    cout<<"NO";
}
cout<<"\n";
return 0;
}
