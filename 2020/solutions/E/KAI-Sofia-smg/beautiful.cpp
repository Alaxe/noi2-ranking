#include <iostream>
using namespace std;
int main(){
    int doKolko,brKrasivi=0,brCifri=0,broqch=0,defaultCifra,cifra[19];
    cin>>doKolko;
    for(int i=1;i<=doKolko;i++){
        broqch=0;
        brCifri=0;
        for(int a=i;a>0;a/=10){
            cifra[brCifri]=a%10;
            brCifri++;
        }
        defaultCifra=cifra[0];
        for(int a=0;a<brCifri;a++){
            if(defaultCifra==cifra[a]){
                broqch++;
            }
        }
        if(broqch==brCifri){
            brKrasivi++;
        }
    }
    cout<<brKrasivi;
    return 0;
}
