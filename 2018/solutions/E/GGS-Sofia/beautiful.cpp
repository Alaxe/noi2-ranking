#include <iostream>
using namespace std;
int main ()
{

long long brCifri,deleno,i=1,chislo=0,x=10,chastno,cifriNaDeleno=0,ideleno,novo=1;
bool krai=false;
cin >> brCifri >> deleno;

ideleno=deleno;
while(ideleno!=0){
   ideleno=ideleno/10;
   cifriNaDeleno++;
}

i=brCifri;
while(brCifri!=1){
    novo=novo*10;
    brCifri--;
}
chislo = novo-1;

    if (cifriNaDeleno>i){
        krai=true;
    }

while ( krai==false ){
 chislo++;
    chastno=chislo/deleno;

    if( chislo/chastno==deleno && chislo%chastno==0 ){
        krai=true;
    }
    if (cifriNaDeleno>i){
        krai=true;
    }
}

if (cifriNaDeleno>i){
    cout << "NO" << endl;
}else{
cout << chislo << endl;
}

return 0;
}



