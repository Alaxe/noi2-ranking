#include <iostream>
using namespace std;
int main () {
long long n, visochini[10000], q, ng=-100, obsht_broi_kapki=0;
cin>>n;
for(int i=0; i<=n-1; i++){
    cin>>visochini[i];
    if(visochini[i]>ng){
        ng=visochini[i];
    }
}
cin>>q;
for(int k=0; k<=n-1; k++){
    obsht_broi_kapki=obsht_broi_kapki+((ng-visochini[k])*q);
}
cout<<obsht_broi_kapki;

return 0;
}
