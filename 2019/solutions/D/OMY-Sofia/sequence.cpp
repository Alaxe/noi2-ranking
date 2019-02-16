#include<iostream>
using namespace std;
int main () {

long long chisloVSredata=1,tursenoChislo,broiChislaVTaziRedica,broiTursene,index=1;
cin>>tursenoChislo>>broiTursene;
for(broiChislaVTaziRedica=1;broiTursene>0;broiChislaVTaziRedica=broiChislaVTaziRedica+2){

 if(tursenoChislo==chisloVSredata){
   broiTursene--;
 } if(tursenoChislo<chisloVSredata){

 broiTursene--;
 if(broiTursene==0){
   cout<<index+tursenoChislo - 1;
   cout<<endl;
   return 0;
 }}else{
 if(broiTursene==0){
   cout<<index+tursenoChislo+2*(chisloVSredata-tursenoChislo)-1;
   cout<<endl;
   return 0;
 }
} index+=broiChislaVTaziRedica;
chisloVSredata=chisloVSredata+1;
}



   return 0;
}
