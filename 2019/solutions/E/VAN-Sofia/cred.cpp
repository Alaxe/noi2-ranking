#include <iostream>
using namespace std;
int main(){
    int n,m,br=1,chislo,chislo2,cifra;
    cin>> n >> m;
    chislo=n;
        while(chislo<=m){
            chislo2=chislo;
            while(chislo2>0){
                cifra=chislo2%10;
                chislo2/=10;
               //cout<< cifra << " ";
                chislo+=cifra;
            }
            //cout<<endl<< chislo << " ";
            if(chislo<=m) br++;
            //cout<< " br e " << br << " ";
        }
        cout<< br;







    return 0;
}

