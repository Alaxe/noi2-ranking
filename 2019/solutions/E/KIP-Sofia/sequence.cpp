#include<iostream>
using namespace std;
bool n=false;
int main() {
    long long turseno,broiRedove,broiObhodeniRedove,namereno,koeChisloDaProverq,broiChisla=1;
    cin>>turseno;
    broiRedove=1000000;
    for(broiObhodeniRedove=0;broiObhodeniRedove<broiRedove && n==false;broiObhodeniRedove++) {
        for(koeChisloDaProverq=1;koeChisloDaProverq<broiObhodeniRedove && n==false;koeChisloDaProverq++) {
            broiChisla++;
            if(koeChisloDaProverq==turseno) {
                namereno=broiChisla;
                n=true;
            }
        }
        for(koeChisloDaProverq=broiObhodeniRedove-1;koeChisloDaProverq>=1;koeChisloDaProverq--) {
            broiChisla++;
        }
    }
    cout<<namereno-turseno<<endl;

return 0;
}
