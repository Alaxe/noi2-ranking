#include <iostream>
using namespace std;

int main () {
    long long m, k, h=-1000000000, a=0, sbor=0, i=0, j=0;
    cin >> m >> k;

    while (a!=m and sbor<k) {
        j++;
        cin >> a;
        if (a%2==0) {
            sbor=sbor+a;
        }
        if (a>m) {
            if (h>m) {
                if (a-m<=h-m) {h=a; i=j;}
            }
            else {
                if (a-m<=m-h) {h=a; i=j;}
            }
        }
        else {
            if (h>m) {
                if (m-a<=h-m) {h=a; i=j;}
            }
            else {
                if (m-a<=m-h) {h=a; i=j;}
            }
        }
    }

    cout << i << " " << sbor << endl;

return 0;
}
