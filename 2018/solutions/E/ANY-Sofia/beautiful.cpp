#include<iostream>
using namespace std;
int main () {
long long n,k,broqch,koeENaiMalkotoNCislo=1,kolkoPutiN=1,koeENaiGolqmotoNChislo=1;
bool imaLiChsloDelqshtoSeNaK=false;
cin>>n>>k;
for(broqch=1;broqch<=n-1;broqch=broqch+1) {
   kolkoPutiN=kolkoPutiN*10;
}
koeENaiMalkotoNCislo=kolkoPutiN;
koeENaiGolqmotoNChislo=kolkoPutiN*10;
for(broqch=koeENaiMalkotoNCislo;broqch<koeENaiGolqmotoNChislo && imaLiChsloDelqshtoSeNaK==false;broqch=broqch+1) {
    if(broqch%k==0) {
        imaLiChsloDelqshtoSeNaK=true;
        cout<<broqch;
    }
}
if(imaLiChsloDelqshtoSeNaK==false) {
    cout<<"NO";
}
return 0;
}
