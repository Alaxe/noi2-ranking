#include<iostream>
using namespace std;
int main () {
long long broi, kapki,a,NgDosega=0,otg=0,i,j;
cin>>broi;
long long visochini[broi];
for (a=0;a<broi;a++) {
    cin>>visochini[a];
for (i=0;i<=a;i++) {
    if (visochini[i]>=NgDosega) {
        NgDosega=visochini[i];
    }
}
}
cin>>kapki;
for (j=0;j<broi;j++) {
    otg=otg+((NgDosega-visochini[j])*kapki);
}
cout<<otg;
return 0;
}
