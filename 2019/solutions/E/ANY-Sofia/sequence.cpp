#include <iostream>
using namespace std;
int main () {
    string tursenoChislo;
    string redica = "112112321123432112345432112345654321123456765432112345678765432112345678987654321";
    cin>>tursenoChislo;
    long long duljinaNaTurseno = tursenoChislo.size();
    long long kolkoRavni=0,iNaTurseno=-1;

    for(int r=0;r<=80;r++) {
        kolkoRavni = 0;
        iNaTurseno = -1;
        if(redica[r]==tursenoChislo[0]) {
            for(int i=0;i<duljinaNaTurseno;i++) {
                if(redica[r+i]-'0' == tursenoChislo[i]-'0') {
                    kolkoRavni++;
                    iNaTurseno = r;
                }
            }
            if(kolkoRavni==duljinaNaTurseno) {
                break;
            }
        }
    }
    cout<<iNaTurseno+1;
    cout<<endl;

    return 0;
}
