/// bavno reshenie
#include <iostream>

using namespace std;

int N,M,p,q, ocenka;
unsigned long long stoyniost[10010];

unsigned long long C(unsigned long long k, unsigned long long l) {
    if (k == 0 || k==l) {
        return 1;
    }
    unsigned long long chislitel = 1;
    for (unsigned long long i = l-k+1; i <= l; ++i) {
        chislitel *= i;
    }
    unsigned long long znamenatel = 1;
    for (unsigned long long i = 1; i<= k; ++i) {
        znamenatel *= i;
    }
    return (chislitel/znamenatel)%1073741824;
}

int main() {
    cin.tie();
    ios_base::sync_with_stdio(false);
    cin >> M >> N >> p >> q;
    ocenka = N-M-p;
    ///y*(p-q) + x*p >= M-N-p
    for (unsigned long long y = 0; y <= (ocenka+(p-q-1))/(p-q); ++y) {
        unsigned long long m = (ocenka-y*(p-q)+p-1)/p;
        //cout << y << " "<< m;
        stoyniost[m] = (max(stoyniost[m],C(m, m+y)))%1073741824;
        //cout << y;
    }
    unsigned long long broi = 0;
    for (long long i = 0; i < 10010; ++i) {
        broi = (broi+stoyniost[i])%1073741824;
    }
    cout << broi << "\n";
    return 0;
}
/**
4500 4560 20 7
*/
