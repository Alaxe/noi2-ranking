#include <iostream>
using namespace std;
int main () {

long long n,a,kapki=0,b;
cin >> n;
long long visochini[n],q,biggest;


for (a=0;a<n;a=a+1) {
    cin >> visochini [a];
     biggest=visochini[0];
    if (visochini[a]>biggest) {
        biggest=visochini[a];
    }
}

cin >> q;

for (b=0;b<n;b=b+1) {
    kapki=kapki+(biggest-visochini[b])*q;
}



cout << kapki;

return 0;
}
