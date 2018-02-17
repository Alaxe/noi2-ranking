#include<iostream>
using namespace std;
int main (){
long long N;
cin>>N;
long long i,j,y,a,parvoChislo,vtoroChislo,proizvedenie,NDNaProizvedenie;
for(i=N-1;i>0;i--){
    for(j=N-2;j>0;j--){
        parvoChislo=i;
        vtoroChislo=j;
        proizvedenie=parvoChislo*vtoroChislo;
        for(y=100000;y>1;y=y/10){
            if(proizvedenie/y%10!=0){
                NDNaProizvedenie=y;
            }
        }
        for(a=1;a<=NDNaProizvedenie;a=a*10){
            if(proizvedenie/a%10==proizvedenie/NDNaProizvedenie%10){

            }
            NDNaProizvedenie=NDNaProizvedenie/10;
        }
    }
}
cout<<parvoChislo<<" "<<vtoroChislo<<endl;
cout<<proizvedenie;
return 0;
}
