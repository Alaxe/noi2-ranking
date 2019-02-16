#include <bits/stdc++.h>
using namespace std;
    void gadno(long long a, long long b) {
        cout << a/b << '.';
        cout << (a%b)*10/b;
        cout << ((a%b)*10%b)*10/b;
        long long c=(((a%b)*10%b)*10%b)*10/b;
        if (((((a%b)*10%b)*10%b)*10%b)*10/b>5) cout << c+1;
        else {
            cout << c;
        }
    }
int main () {
    long long s, k, a, c, b, d, i, m, n;
    cin >> s >> k >> a >> b >> c >> d;

    if (k>=d*4*s) {
        gadno(k, 4*s);
        cout << ' ';
        gadno(k, 4*s);
        cout << ' ';
        gadno(k, 4*s);
        cout << ' ';
        gadno(k, 4*s);
        cout << endl;
        return 0;
    }
    m=k/(4*d)%4+1;
    n=k%(4*d);
    if (k%(4*d)==0) {
        m--;
        n=4*d;
    }
    if (m==4) {
        if (n<=c) {
            cout << n << ".000 ";
            cout << "0.000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
        }
        else {
            if (n<=c+a) {
            cout << c << ".000 ";
            cout << n-c << ".000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
            }
            else {
            if (n<=c+2*b) {
                cout << c << ".000 ";
                if ((n-c)%2==1) {
                    cout << (n-c)/2 << ".500 ";
                    cout << (n-c)/2 << ".500 ";
                }
                else {
                    cout << (n-c)/2 << ".000 ";
                    cout << (n-c)/2 << ".000 ";
                }
                cout << "0.000" << endl;;
            }
            else {
                if (n<=c+3*b) {
                    cout << c << ".000 ";
                    cout << b << ".000 ";
                    cout << b << ".000 ";
                    cout << n-c-2*b << ".000 ";
                }
                else {
                if (n<=4*c) {
                cout << c << ".000 ";
                gadno(n-c, 3);
                cout << ' ';
                gadno(n-c, 3);
                cout << ' ';
                gadno(n-c, 3);
                cout << endl;
                }
                else {
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << endl;
                }
                }
            }
            }
        }
    }
    if (m==3) {
        if (n<=b) {
            cout << n << ".000 ";
            cout << "0.000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
        }
        else {
            if (n<=2*c) {
                if (n%2==1) {
                    cout << n/2 << ".500 ";
                    cout << n/2 << ".500 ";
                }
                else {
                    cout << n/2 << ".000 ";
                    cout << n/2 << ".000 ";
                }
            cout << "0.000 ";
            cout << "0.000" << endl;;
            }
            else {
            if (n<=2*c+a) {
                cout << c << ".000 ";
                cout << c << ".000 ";
                cout << n-2*c << ".000 ";
                cout << "0.000" << endl;;
            }
            else {
                if (n<=4*c) {
                    cout << c << ".000 ";
                    cout << c << ".000 ";
                gadno(n-2*c, 2);
                cout << ' ';
                gadno(n-2*c, 2);
                cout << endl;
                }
                else {
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << endl;
                }
                }
            }
            }
        }
     if (m==2) {
        if (n<=b) {
            cout << n << ".000 ";
            cout << "0.000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
        }
        else {
            if (n<=b+a) {
            cout << b << ".000 ";
            cout << n-b << ".000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
            }
            else {
            if (n<=3*b) {
                cout << b << ".000 ";
                if ((n-b)%2==1) {
                    cout << (n-b)/2 << ".500 ";
                    cout << (n-b)/2 << ".500 ";
                }
                else {
                    cout << (n-b)/2 << ".000 ";
                    cout << (n-b)/2 << ".000 ";
                }
                cout << "0.000" << endl;;
            }
            else {
                if (n<=3*c) {
                gadno(n, 3);
                cout << ' ';
                gadno(n, 3);
                cout << ' ';
                gadno(n, 3);
                cout << ' ';
                cout << "0.000" << endl;
                }
                else {
                if (n<=4*c) {
                cout << c << ".000 ";
                cout << c << ".000 ";
                cout << c << ".000 ";
                cout << n-3*c << ".000" << endl;
                }
                else {
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << endl;
                }
                }
            }
            }
        }
    }
    if (m==1) {
        if (n<=a) {
            cout << n << ".000 ";
            cout << "0.000 ";
            cout << "0.000 ";
            cout << "0.000" << endl;;
        }
        else {
            if (n<=2*c) {
                if (n%2==1) {
                    cout << n/2 << ".500 ";
                    cout << n/2 << ".500 ";
                }
                else {
                    cout << n/2 << ".000 ";
                    cout << n/2 << ".000 ";
                }
            cout << "0.000 ";
            cout << "0.000" << endl;;
            }
            else {
            if (n<=2*c+b) {
                cout << c << ".000 ";
                cout << c << ".000 ";
                cout << n-2*c << ".000 ";
                cout << "0.000" << endl;;
            }
            else {
                if (n<=2*c+2*b) {
                    cout << c << ".000 ";
                    cout << c << ".000 ";
                    gadno(n-2*c, 2);
                    cout << ' ';
                    gadno(n-2*c, 2);
                    cout << endl;
                }
                else {
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << ' ';
                gadno(n, 4);
                cout << endl;
                }
            }
            }
        }
    }
return 0;
}

