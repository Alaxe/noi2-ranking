#include<iostream>
using namespace std;
int main () {
long long n,k,p,m,x;
cin>>n>>k;
for(x=2;x>50;x++)
if(n==1){
    for(p=1;p<10;p++){
    if(p-k==k*2 or p-k==k){

    }else
    if(p%k==0){
    cout<<p;
    }
    }
}
if(n==2){
        if(k==1){
            cout<<10;}
    if(k==2){
            cout<<10;}
if(k==3){
            cout<<12;}
            if(k==4){
            cout<<12;}
            if(k==5){
            cout<<10;}if(k==6){
            cout<<12;}if(k==7){
            cout<<14;}if(k==8){
            cout<<16;}if(k==9){
            cout<<18;}
    for(p=10;p<100;p++){
   if(p-k>=k*1){
    }else{


        if(p%k==0){
    cout<<p;

    }
    }
    }
}
return 0;
}
