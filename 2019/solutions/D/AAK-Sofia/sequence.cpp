#include <iostream>
using namespace std;
int main(){
long long index,koeChislo,zaKoiPyt,stypka=0,index2,chislo,broiSreshtaniaNaChislo=0;
bool nagore=true;
cin>>koeChislo>>zaKoiPyt;
for(index=1;zaKoiPyt>0;index++){
    for(index2=1,chislo=1,nagore=true;index2<index*2;index2++){
        stypka++;
        if(chislo==koeChislo){
            broiSreshtaniaNaChislo++;
        }
        if(broiSreshtaniaNaChislo==zaKoiPyt){
            cout<<stypka;
            zaKoiPyt=0;
            index2=index*2;
        }
        if(chislo<index && nagore){
            chislo++;
        }else{
            nagore=false;
            chislo--;
            if(chislo==0){
                index2=index*2;
            }
        }
    }
}
return 0;
}
