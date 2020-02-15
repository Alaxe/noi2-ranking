#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, w1, w2, a[210], os, op, ok, k;
queue<int> q;

void rek (int s, int p, int k) {
int i;
bool fl=true;
    k ++;
    cout << s << " " << a[p] << " " << k << endl;
    for (i = p+1; i <= n; i ++) {
        if (s-a[i] > 0) {
            fl = true;
            rek (s-a[i], i, k);
        }
        if (s-a[i] == 0) {
//            cout << "OTGOVOR " << endl;
//            cout << a[p] << " " << s << " " << k << endl;
            q.push(a[p]);
            q.push(s);
            os = s;
            op = p;
            ok = k;
            return ;
        }
    }
    if (s == os+op && k == ok-1) {
        ;
    }
//    cout << "vr " << s << " " << a[p] << " " << k << endl;
//    cout << "   " << os << " " << a[op] << " " << ok << endl;
}

int main () {
int i, j;
    cin >> n >> w1 >> w2;// w1 > w2
    if (w1 < w2) swap (w1,w2);
    for (i = 1;i <= n; i ++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
//    rek (w1, 0, 0);
    for (i = 1; i <= w1; i ++){
        for (j  = 1; j <= n; j ++) {

        }
    }
    cout << w1+w2 << endl;
    return 0;
}
/*
5 10 14
4 5 6 7 8

5 10 14
2 4 5 7 8
*/
