#include <iostream>
using namespace std;
int main (){

long long n,q,index,NaiMnogoMM=0,nujniKapkiZaRavnaVisochina;
cin>>n;
long long cvetia[n],kolkoMMOstavat[n];
for(index=0;index<n;index=index+1){
    cin>>cvetia[index];
    if(cvetia[index]>NaiMnogoMM){
        NaiMnogoMM=cvetia[index];
    }
}
cin>>q;
for(index=0;index<n;index=index+1){
    if(cvetia[index]<=NaiMnogoMM){
        kolkoMMOstavat[index]=NaiMnogoMM-cvetia[index];
    }
}
nujniKapkiZaRavnaVisochina=0;
for(index=0;index<n;index=index+1){
    nujniKapkiZaRavnaVisochina=nujniKapkiZaRavnaVisochina+kolkoMMOstavat[index];
}
nujniKapkiZaRavnaVisochina=nujniKapkiZaRavnaVisochina*q;
cout<<nujniKapkiZaRavnaVisochina;

return 0;
}
