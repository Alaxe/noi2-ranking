#include<iostream>
using namespace std;
int main () {
long long n,q;
cin>>n;
long long visochini[n],iv,naiGolqmoCvete,sKolko[n],kolkoKapkiVoda=0;
for(iv=0;iv<n;iv=iv+1) {
    cin>>visochini[iv];
}
cin>>q;
naiGolqmoCvete=visochini[iv-1];
for(iv=0;iv<n;iv=iv+1) {
    if(visochini[iv]>naiGolqmoCvete) {
        naiGolqmoCvete=visochini[iv];
    }
}
for(iv=0;iv<n;iv=iv+1) {
    sKolko[iv]=naiGolqmoCvete-visochini[iv];
}
for(iv=0;iv<n;iv=iv+1) {
    kolkoKapkiVoda=kolkoKapkiVoda+sKolko[iv]*q;
}
cout<<kolkoKapkiVoda;
return 0;
}
