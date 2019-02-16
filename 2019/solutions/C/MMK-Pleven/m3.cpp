#include <iostream>
#include <cstdio>
using namespace std;

int s, k, a, b, c, d, vid;
float o1, o2, o3, o4;

int main () {
    cin >> s >> k >> a >> b >> c >> d;
    if (k%(4*d) == 0) {
        k = 4*d;
        o1 = o2 = o3 = o4 = float(d);
        printf ("%0.3f ", o1);
        printf ("%0.3f ", o2);
        printf ("%0.3f ", o3);
        printf ("%0.3f ", o4);
        return 0;

    }
    vid = (k/(4*d))%4;
    if (vid == 0 && k >= 4*d) vid = 4;
    else vid ++;
    k = k % (4*d);
    //cout << vid << endl;
    if (vid == 1) {
        if (k >= 4*c) {
            o1 = o2 = o3 = o4 = float(k)/4;
        }
        else if (k > 2*c) { // preliva
            o1 = o2 = c;
            k = k - 2*c;
            if (k < 2*b) {
                o3 = min(b,k);
                k -= b;
                o4 = max(k,0);
            }
            else {
                o3 = o4 = float(k)/2;
            }
        }
        else {
            if (k >= 2*a) {
                o1 = o2 = float(k)/2;
                //cout << "YES  " << k << endl;
            }
            else {
                o1 = min (a,k);
                k -= a;
                o2 = max (0,k);
            }
        }
    }
    else if (vid == 2) {
        if (k >= 4*c) {
            o1 = o2 = o3 = o4 = float(k)/4;
        }
        else if (k >= 3*c) {
            o1 = o2 = o3 = c;
            o4 = k - 3*c;
        }
        else {
            if (k <= b) o1 = k;
            else {
                if (k >= 3*b) {
                    o1 = o2 = o3 = float(k)/3;
                }
                else {
                    o1 = b; k -= b;
                    if (k >= 2*a) {
                        o2 = o3 = float(k)/2;
                    }
                    else {
                        o2 = min (a,k); k -= a;
                        o3 = max (k,0);
                    }
                }
            }
        }
    }
    else if (vid == 3) {
        if (k >= 4*c) {
            o1 = o2 = o3 = o4 = float(k)/4;
        }
        else if (k >= 2*c) {
            o1 = o2 = c; k -= 2*c;
            if (k >= 2*a) {
                o3 = o4 = float(k)/2;
            }
            else {
                o3 = min (a,k); k -= a;
                o4 = max (k,0);
            }
        }
        else {
            if (k >= 2*b) {
                o1 = o2 = float(k)/2;
            }
            else {
                o1 = min (b,k); k -= b;
                o2 = max (k,0);
            }
        }
    }
    else if (vid == 4) {
        if (k >= 4*c) {
            o1 = o2 = o3 = o4 = float(k)/4;
        }
        else if (k >= 2*b+c) {
            o1 = c; o2 = o3 = b; k -= (c+2*b);
            o4 = k;
        }
        else {
            if (k <= c) {
                o1 = k;
            }
            else {
                o1 = c;
                k -= c;
                if (k >= 2*a) {
                    o2 = o3 = float(k)/2;
                }
                else {
                    o2 = min (k, a); k -= a;
                    o3 = max (k, 0);
                }
            }
        }
    }
    printf ("%0.3f ", o1);
    printf ("%0.3f ", o2);
    printf ("%0.3f ", o3);
    printf ("%0.3f ", o4);
    return 0;
}
/*
3 11
2 3 4 5

3 7
2 3 4 5
*/
