#include<iostream>
using namespace std;
int main (){
    long long k,m,chisla[201],sbor=0,nomer=0,minR=1000,minSega=0,nomer2=1;
    cin>>m>>k>>chisla[1];
    if(chisla[nomer+1]>m){
        minSega=chisla[nomer+1]-m;
    }else{
        minSega=m-chisla[nomer+1];
    }
    while(nomer<200 and sbor<=k){
        nomer++;
        if(chisla[nomer]%2==0){
            sbor=sbor+chisla[nomer];
        }
        if(sbor>k){
            break;
        }
        if(chisla[nomer]>m){
            minSega=chisla[nomer]-m;
        }else{
            minSega=m-chisla[nomer+1];
        }
        if(minSega<=minR && nomer2<=nomer){
            minR=minSega;
            nomer2=nomer;
        }
        cin>>chisla[nomer+1];
    }
    cout<<nomer2<<" "<<sbor;
return 0;
}
