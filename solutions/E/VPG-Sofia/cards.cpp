#include <iostream>
using namespace std;
bool redica (long long a, long long b, long long c, long long d) {
    if (a<c or b<d) swap(a, b);
    if (a<c or b<d) return false;
    return true;
}
int main ()
{
    long long n, a, b, c, d, tekusht, maxredica=0;
    cin >> n;
    tekusht=1;
    cin >> a >> b;
    for (int i=2;i<=n;i++) {
        cin >> c >> d;
        if (!redica(a, b, c, d)) {
            if (maxredica<tekusht) maxredica=tekusht;
            tekusht=1;
        } else tekusht++;
        a=c;b=d;
    }
    if (maxredica<tekusht) maxredica=tekusht;
    cout << maxredica << endl;
    return 0;
}
