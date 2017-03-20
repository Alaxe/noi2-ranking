#include <iostream>
using namespace std;
int main () {
    long long M,K,chislo,chetsb=0,malkar,br=0,ch;
    cin >> M >> K;
    while (chetsb<=K) {
            br++;
        cin >> chislo;
        if (chislo%2==0) {
            chetsb=chetsb+chislo;
        }
        if (br==1 and chislo>=M) {
            malkar=chislo-M;
            ch=br;
        }
        else if (br==1 and chislo<M){
            malkar=M-chislo;
            ch=br;
        }
        if (chislo>=M) {
            if (chislo-M<=malkar) {
                malkar=chislo-M;
                ch=br;
            }
        }
        if (chislo<M) {
            if (M-chislo<=malkar) {
            malkar=M-chislo;
            ch=br;
            }
        }
    }
        cout << ch << " " << chetsb << endl;
    return 0;
}
