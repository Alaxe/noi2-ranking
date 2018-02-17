#include <iostream>
using namespace std;
int main ()
{

long long brCvetq,cvetq[10000],kapki,NaiGol=0,razlika,obshtoVoda=0;
cin >> brCvetq;

for (int i=0;i<brCvetq;i++){
    cin >> cvetq[i];
}
cin >> kapki;

for (int i=0;i<brCvetq;i++){
    if (cvetq[i]>NaiGol){
        NaiGol=cvetq[i];

    }
}
for (int i=0;i<brCvetq;i++){
    razlika=NaiGol-cvetq[i];
    razlika=razlika*kapki;
    obshtoVoda=obshtoVoda+razlika;
}
cout << obshtoVoda << endl;

return 0;
}
