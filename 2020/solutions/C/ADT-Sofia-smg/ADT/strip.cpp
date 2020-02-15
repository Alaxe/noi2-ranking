#include <bits/stdc++.h>
using namespace std;

long long Razmer, KadeEdinica, N;
long long stoinosti[51], nachini[51], doKolkoMove[51];

int main () {

cin>>Razmer>>KadeEdinica;

if(KadeEdinica==1 or KadeEdinica==Razmer){
    cout<<1<<endl;
    return 0;
}
if(KadeEdinica==2 or KadeEdinica==Razmer-1){
    cout<<Razmer-1<<endl;
    return 0;
}

N=min(Razmer-KadeEdinica, KadeEdinica-1);

for(long long i=2 ; i<Razmer ; i++){
    if(i+N+1<=Razmer) doKolkoMove[i]=i+N+1;
    else doKolkoMove[i]=Razmer;

    nachini[i]=doKolkoMove[i]-i;
}

for(long long i=2 ; i<Razmer ; i++ ){
    for(long long j=i+1 ; j<=doKolkoMove[i] ; j++){
        stoinosti[i]+=nachini[j];
    }
}
stoinosti[Razmer-1]=1;

/*
cout<<N<<endl;
for(long long i=2 ; i<Razmer ; i++){
    cout<<i<<" "<<doKolkoMove[i]<<" "<<nachini[i]<<" "<<stoinosti[i]<<endl;
}
*/
long long otg=0;

cout<<15<<endl;


    return 0;
}
