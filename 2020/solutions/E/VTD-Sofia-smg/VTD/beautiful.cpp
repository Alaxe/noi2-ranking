#include<iostream>
using namespace std;
int main(){
long long N,YesNo=0,brKrasiviChisla=0,brIzminati=0;
cin>>N;
long long brCifriNaN=0,zapaziN;
if(N>=10){
    zapaziN=N;
    while(zapaziN>0){
        brCifriNaN=brCifriNaN+1;
        zapaziN=zapaziN/10;
    }
    zapaziN=N;
    //cifri na N//
    for(long long ia=1;ia<brCifriNaN;ia=ia+1){
        zapaziN=zapaziN/10;
    }
    //cout<<zapaziN;
    long long nqkakvoChislo;
    nqkakvoChislo=zapaziN;
    for(long long z=1;brCifriNaN>z;z=z+1){
        nqkakvoChislo=nqkakvoChislo*10+zapaziN;
    }
    //cout<<nqkakvoChislo;
    if(nqkakvoChislo>N && zapaziN!=1){
        brKrasiviChisla=(brCifriNaN-1)*9+zapaziN-1;
    }else{
        if(nqkakvoChislo>N && zapaziN==1){
            brKrasiviChisla=(brCifriNaN-1)*9;
        }else{
            if(nqkakvoChislo<=N){
                brKrasiviChisla=(brCifriNaN-1)*9+zapaziN;
            }
        }
    }
}else{
    if(N<=9){
        brKrasiviChisla=N;
    //1,2,3,4,5,6,7,8,9//
    }
}
cout<<brKrasiviChisla;
return 0;
}
