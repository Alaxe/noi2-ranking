#include <iostream>
#include<cstring>
using namespace std;
int main(){
long long N,L,izgubeniPechati[3],broqch,broqch2,chislo=0,cifra[100000],kopieNaChislo;
do{
cin>>N>>L;
}while(N>1000000 or N<1 or L<1 or L>3);
for(broqch=0;broqch<L;broqch++){
    cin>>izgubeniPechati[broqch];
   }
      for(broqch2=0;broqch2<N;broqch2++){
            kopieNaChislo=chislo;
        for(broqch=0;kopieNaChislo!=0;broqch++){
            cifra[broqch]=kopieNaChislo%10;
            kopieNaChislo=kopieNaChislo/10;
            if(cifra[broqch]==izgubeniPechati[0] or cifra[broqch]==izgubeniPechati[1] or cifra[broqch]==izgubeniPechati[2]){
                broqch2--;
            }
        }
chislo++;
      }cout<<chislo-L<<endl;

return 0;
}
