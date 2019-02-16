#include  <iostream>
#include <cmath>
using  namespace  std;
unsigned long long nod(unsigned long long a, unsigned long long b){
    while(b!=0){
        a%=b;
        swap(a, b);
    }
    return a;
}
int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
unsigned long long nok, n, p; cin>>n;
cin>>p;
if(n==1){
    if((double)sqrt(p)==(unsigned long long)(sqrt(p))) cout<<sqrt(p)<<'\n';
    else cout<<p*p<<'\n';
    return 0;
}
for(unsigned long long i=1; i<n; i++){
    unsigned long long x; cin>>x;
    if(i==1) {
        nok=(p*x)/nod(p, x);
    }
    else nok=(nok*x)/nod(nok, x);
}
for(unsigned long long i=1; i<10000; i++) {
    unsigned long long koren=(sqrt(nok*i));
    if((double)sqrt(nok*i)==(unsigned long long)(koren)) {
        cout<<koren<<'\n';
        return 0;
    }
}
return 0;
}
