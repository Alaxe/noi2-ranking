#include <iostream>
using namespace std;
int main () {
    long long N,palindrom=0,c,d;
    cin >> N;
    for (long long a=N-1;a>=1;a--) {
        for (long long b=N-1;b>=1;b--) {
                if (a*b<10) {
                if (a*b>palindrom) {
                    palindrom=a*b;
                    c=a;
                    d=b;
                    b=1;
                }
                }
                else if (a*b>9 and a*b<100) {
                    if (a*b%10==a*b/10 and a*b>palindrom) {
                            palindrom=a*b;
                            c=a;
                            d=b;
                    b=1;
                    }
                }
                else if (a*b>99 and a*b<1000) {
                    if (a*b%100==a*b/100 and a*b>palindrom) {
                            palindrom=a*b;
                            c=a;
                            d=b;
                    b=1;
                    }
                }
                else if (a*b>999 and a*b<10000) {
                    if (a*b%10==a*b/1000 and a*b%1000/100==a*b%1000%100/10 and a*b>palindrom) {
                            palindrom=a*b;
                            c=a;
                            d=b;
                    b=1;
                    }
                }
                else if (a*b>9999 and a*b<100000) {
                    if (a*b%10==a*b/10000 and a*b%10000/1000==a*b%10000%1000%100/10 and a*b>palindrom) {
                            palindrom=a*b;
                            c=a;
                            d=b;
                    b=1;
                    }
                }
                    else if (a*b>99999 and a*b<1000000) {
                    if (a*b%10==a*b/100000 and a*b%100000/10000==a*b%100000%10000%1000%100/10 and a*b%100000%10000/1000==a*b%100000%10000%1000/100 and a*b>palindrom) {
                            palindrom=a*b;
                            c=a;
                            d=b;
                    b=1;
                    }
                }
            }
        }
    cout << d << " " << c << "\n" << palindrom << endl;
    return 0;
}
