#include<iostream>
using namespace std;
int main (){
long long i,M,K,sbor=0,naiblizkoChislo=1,chisloNaEva[200];
cin>>M>>K;
for(i=1;i<=200;i++){
    if(sbor<K){
        cin>>chisloNaEva[i];
        if(chisloNaEva[i]%2==0){
            sbor=sbor+chisloNaEva[i];
        }
        if(chisloNaEva[i]<=M && chisloNaEva[i]>=naiblizkoChislo || chisloNaEva[i]>=M && chisloNaEva[i]<=naiblizkoChislo || naiblizkoChislo-M==M-chisloNaEva[i] ||naiblizkoChislo+M==M-chisloNaEva[i]){
            naiblizkoChislo=chisloNaEva[i];
        }
    }
}
cout<<naiblizkoChislo<<" "<<sbor;
return 0;
}
