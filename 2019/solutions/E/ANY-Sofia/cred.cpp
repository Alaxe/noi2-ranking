#include <iostream>
using namespace std;
int main () {
    long long nachalnoChislo,krainoChislo;
    cin>>nachalnoChislo>>krainoChislo;

    long long duljinaNaSegChislo=0,segChislo,cifriNaSegChislo[10];
    for(int i=1;i<nachalnoChislo;i*=10) {
        duljinaNaSegChislo++;
    }
    if(duljinaNaSegChislo>=1) {
        cifriNaSegChislo[0] = nachalnoChislo%10;
    }
    if(duljinaNaSegChislo>=2) {
        cifriNaSegChislo[1] = (nachalnoChislo/10)%10;
    }
    if(duljinaNaSegChislo>=3) {
        cifriNaSegChislo[2] = (nachalnoChislo/100)%10;
    }
    if(duljinaNaSegChislo>=4) {
        cifriNaSegChislo[3] = (nachalnoChislo/1000)%10;
    }
    if(duljinaNaSegChislo>=5) {
        cifriNaSegChislo[4] = (nachalnoChislo/10000)%10;
    }
    if(duljinaNaSegChislo>=6) {
        cifriNaSegChislo[5] = (nachalnoChislo/100000)%10;
    }
    long long br=0;
    for(segChislo = nachalnoChislo;segChislo<krainoChislo;br++) {
        for(int i=0;i<duljinaNaSegChislo;i++) {
            duljinaNaSegChislo=0;
            for(int k=1;k<segChislo;k*=10) {
                duljinaNaSegChislo++;
            }
            if(duljinaNaSegChislo>=1) {
                cifriNaSegChislo[0] = segChislo%10;
            }
            if(duljinaNaSegChislo>=2) {
                cifriNaSegChislo[1] = (segChislo/10)%10;
            }
            if(duljinaNaSegChislo>=3) {
                cifriNaSegChislo[2] = (segChislo/100)%10;
            }
            if(duljinaNaSegChislo>=4) {
                cifriNaSegChislo[3] = (segChislo/1000)%10;
            }
            if(duljinaNaSegChislo>=5) {
                cifriNaSegChislo[4] = (segChislo/10000)%10;
            }
            if(duljinaNaSegChislo>=6) {
                cifriNaSegChislo[5] = (segChislo/100000)%10;
            }
        }
        for(int j=0;j<duljinaNaSegChislo;j++) {
            segChislo+=cifriNaSegChislo[j];
        }
        cout<<segChislo<<" ";
    }
    cout<<endl<<br;
    cout<<endl;
    return 0;
}
