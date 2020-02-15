#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int strip[n];
    for (int i = 0; i < n; i++) {
        cin >> strip[i];
    }
    sort(strip, strip + n);
    int m;
    cin >> m;
    for (int q = m; q > 0; q--) {
        if (q != m) {
            cout << "\n";
        }
        int x, y, a = -1, b = -1;
        cin >> x >> y;
        if (x > strip[n - 1] || y < strip[0]) {
            cout << "0";
            continue;
        }
        int o = n / 2;
        int stages = 0;

        if (x < strip[0] && y > strip[n - 1]) {
            cout << n;
            continue;
        }
        if (x < strip[0]) {
            stages = 1;
            while (stages == 1) {
                if (strip[o] == y) {
                    if (strip[o + 1] == y) {
                        o++;
                    } else {
                        stages = 2;
                        b = o;
                    }
                } else if (y > strip[o] &&  y < strip[o + 1]) {
                    b = o;
                    stages = 2;
                } else if (y < strip[o] && y > strip[o - 1]) {
                    stages = 2;
                    b = o - 1;
                } else if (y < strip[o]) {
                    o /= 2;
                } else if (y > strip[o]) {
                    o = (n - o) / 2 + o;
                }
            }
            cout << b + 1;
            continue;
        }
        if (y > strip[n - 1]) {
            while (stages == 0) {
                if (strip[o] == x) {
                    if (strip[o - 1] == x) {
                        o--;
                    } else {
                        stages = 1;
                        a = o;
                        o = n / 2;
                    }
                } else if (x > strip[o] &&  x <= strip[o + 1]) {
                    a = o + 1;
                    o = n / 2;
                    stages = 1;
                } else if (x < strip[o] && x > strip[o - 1]) {
                    stages = 1;
                    a = o;
                    o = n / 2;
                } else if (x < strip[o]) {
                    o /= 2;
                } else if (x > strip[o]) {
                    o = (n - o) / 2 + o;
                }
            }
            cout << n - a;
            continue;
        }
        while (stages != 2) {
            if (stages == 0) {
                if (strip[o] == x) {
                    if (strip[o - 1] == x) {
                        o--;
                    } else {
                        stages = 1;
                        a = o;
                        o = n / 2;
                    }
                } else if (x > strip[o] &&  x <= strip[o + 1]) {
                    a = o + 1;
                    o = n / 2;
                    stages = 1;
                } else if (x < strip[o] && x > strip[o - 1]) {
                    stages = 1;
                    a = o;
                    o = n / 2;
                } else if (x < strip[o]) {
                    o /= 2;
                } else if (x > strip[o]) {
                    o = (n - o) / 2 + o;
                }
            }
            if (stages == 1) {
                if (strip[o] == y) {
                    if (strip[o + 1] == y) {
                        o++;
                    } else {
                        stages = 2;
                        b = o;
                    }
                } else if (y > strip[o] &&  y < strip[o + 1]) {
                    b = o;
                    stages = 2;
                } else if (y < strip[o] && y > strip[o - 1]) {
                    stages = 2;
                    b = o - 1;
                } else if (y < strip[o]) {
                    o /= 2;
                } else if (y > strip[o]) {
                    o = (n - o) / 2 + o;
                }
            }
        }
        cout << b - a + 1;
    }
    return 0;
}
