#include<iostream>
using namespace std;
int main(){
long long BroiCifriNaChisloto,delitel,NmKrasivoChislo,chislotoStart,Priclqchvane;
cin>>BroiCifriNaChisloto>>delitel;
chislotoStart=1;
Priclqchvane=0;
while(BroiCifriNaChisloto>1){
    chislotoStart=chislotoStart*10;
    BroiCifriNaChisloto=BroiCifriNaChisloto-1;
}
while(Priclqchvane==0){
        if(chislotoStart%delitel==0){
            Priclqchvane=1;
            NmKrasivoChislo=chislotoStart;
        }
    if(chislotoStart==99999999999999999){
            cout<<"NO";
            return 0;
    }
    chislotoStart=chislotoStart+1;
}
cout<<NmKrasivoChislo;
return 0;
}
