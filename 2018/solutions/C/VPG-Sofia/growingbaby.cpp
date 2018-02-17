#include <iostream>
#include <math.h>
using namespace std;
int po;
long long n, m, q, p, ans;
long long modul(long long a) {
    if (a<po) return a;
    return a%po;
}
void ways(long long kg, bool is) {
    if (kg>=n-m) {
        ans++;
        if (ans==po) ans=0;
        return;
    }
    if (kg<0 or kg>n-m+p or (kg==0 and !is)) return;
    ways(kg+p,true);
    if (is) ways(kg-q,false);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> p >> q;
    po=1;
    for (int i=0;i<30;i++) po*=2;
    ways(0,true);
    cout << ans << endl;
    return 0;
}
