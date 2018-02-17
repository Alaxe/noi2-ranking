#include<iostream>
using namespace std;
int main (){
    int n,k,cifriNaK=0,cifriNaRNCK=0,cifriNaBNCK=0,randomNCifrenoK=0,betaNCifrenoK=0;
    cin>>n>>k;
    randomNCifrenoK=k;
    for(k;k>0;k/=10){
        cifriNaK++;}
    k=randomNCifrenoK;
    cifriNaRNCK=cifriNaK;
    if(cifriNaK>n){
        cout<<"NO"<<endl;}
    else{for(cifriNaRNCK;cifriNaRNCK<n;cifriNaRNCK++){
            randomNCifrenoK*=10;}
        for(cifriNaBNCK=n;cifriNaBNCK==n;){
            cifriNaBNCK=0;
            betaNCifrenoK=randomNCifrenoK-k;
            while(betaNCifrenoK>0){
                cifriNaBNCK++;
                betaNCifrenoK/=10;}
            if(cifriNaBNCK==n){randomNCifrenoK-=k;}
        }
        cout<<randomNCifrenoK<<endl;}
    return 0;}
