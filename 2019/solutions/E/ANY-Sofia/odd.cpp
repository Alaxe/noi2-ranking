#include <iostream>
using namespace std;
int main () {
    long long otKolko,doKolko,kolkoDelitelq=0,otgovor=0;
    cin>>otKolko>>doKolko;
    for(int delimo=otKolko;delimo<doKolko;delimo++) {
        kolkoDelitelq=0;
        for(int delitel=1;delitel<doKolko;delitel++) {
            if(delimo%delitel==0) {
                kolkoDelitelq++;
            }
        }
        if(kolkoDelitelq%2==1) {
            otgovor++;
        }
    }
    cout<<otgovor;
    cout<<endl;

    return 0;
}
