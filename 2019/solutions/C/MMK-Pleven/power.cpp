#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll n, k, i, a[10001], p, j;
bool fl;

ll step (ll chislo, ll stepen) {
ll izh = 1;
    for (ll f = 1; f <= stepen; f ++) {
        izh = izh*chislo;
    }
    return izh;
}

int main () {
//    cout << step(2,62) << endl;
    cin >> n >> k;
    for (i = 1; i <= n; i ++) cin >> a[i];
    i = 0;
    while (1) {
        i ++;
        p = step (i,k);
        //cout << p << endl;
        fl = true;
        for (j = 1; j <= n; j ++) {
            if (p % a[j] != 0) {
                fl = false;
                break;
            }
        }
        if (fl == true) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
/*
4 3
3 4 5 6
*/
