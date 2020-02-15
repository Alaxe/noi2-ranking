#include <bits/stdc++.h>
using namespace std;
string preobrazuvaneVNaiMalko(string duma){
    string izhod=duma;
    char naiElement, naKoqBukvaE='A';
    unsigned long long bukviPrevedeni=0;
    while(bukviPrevedeni<duma.size()){
        naiElement=*min_element(duma.begin(), duma.end());
        for(unsigned long long i=0; i<duma.size(); i++){
            if(duma[i]==naiElement){
                duma[i]='Z'+1;
                izhod[i]=naKoqBukvaE;
                bukviPrevedeni++;
            }
        }
        naKoqBukvaE++;
    }
    return izhod;
}
string preobrazuvaneVNaiGolqmo(string duma){
    string izhod=duma;
    char naiElement, naKoqBukvaE='Z';
    unsigned long long bukviPrevedeni=0;
    while(bukviPrevedeni<duma.size()){
        naiElement=*max_element(duma.begin(), duma.end());
        for(unsigned long long i=0; i<duma.size(); i++){
            if(duma[i]==naiElement){
                duma[i]='A'-1;
                izhod[i]=naKoqBukvaE;
                bukviPrevedeni++;
            }
        }
        naKoqBukvaE--;
    }
    return izhod;
}
string vhod;
int main(){
    cin >> vhod;
    cout << preobrazuvaneVNaiMalko(vhod) << endl << preobrazuvaneVNaiGolqmo(vhod) << endl;
    return 0;
}
