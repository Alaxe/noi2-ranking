#include<iostream>
using namespace std;
int main(){
long long K,M,sborotchetni,naiblizkochilo,nomer;
cin>>M;
cin>>K;
nomer=0;
sborotchetni=0;
long long izmislenochislo,brojchisla;
brojchisla=0;
while(brojchisla<=200 or sborotchetni<=K){
    cin>>izmislenochislo;
    if(izmislenochislo%2==0){
      sborotchetni=sborotchetni+izmislenochislo;
        if(sborotchetni>K){
            cout<<nomer<<" "<<sborotchetni;
        }
    }
    long long nmrazlika=100000;
    if(izmislenochislo-M<nmrazlika){
    nmrazlika=izmislenochislo-M;}
nomer++;
}
if(sborotchetni<=K){
    cout<<" ";

}
//naiblizkochilo=
cout<<nomer<<" "<<sborotchetni;
return 0;
}

