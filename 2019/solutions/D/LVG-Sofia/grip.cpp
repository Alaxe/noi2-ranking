#include <bits/stdc++.h>
using namespace std;

int start_day (int d, int m, int y) {
    int st;
    if (y == 2019) {
        if (m == 1) {
            st = 2;
        }
        if (m == 2) {
            st = 5;
        }
        if (m == 3) {
            st = 5;
        }
        if (m == 4) {
            st = 1;
        }
        if (m == 5) {
            st = 3;
        }
        if (m == 6) {
            st = 6;
        }
        if (m == 7) {
            st = 1;
        }
        if (m == 8) {
            st = 4;
        }
        if (m == 9) {
            st = 7;
        }
        if (m == 10) {
            st = 2;
        }
        if (m == 11) {
            st = 5;
        }
        if (m == 12) {
            st = 7;
        }

    }
    if (y == 2020) {
        if (m == 1) {
            st = 3;
        }
        if (m == 2) {
            st = 6;
        }
        if (m == 3) {
            st = 7;
        }
        if (m == 4) {
            st = 3;
        }
        if (m == 5) {
            st = 5;
        }
        if (m == 6) {
            st = 1;
        }
        if (m == 7) {
            st = 3;
        }
        if (m == 8) {
            st = 1;
        }
        if (m == 9) {
            st = 2;
        }
        if (m == 10) {
            st = 4;
        }
        if (m == 11) {
            st = 7;
        }
        if (m == 12) {
            st = 2;
        }

    }
    int dw;
    dw = (st + (d - st) % 7)% 7;
    return dw;
}

int main() {
    long long n;
    string date;
    cin >> date >> n;
    n++;
    int d, m, y;
    if (date[2] == '/') {
        d = (date[1] - 48) + (date[0] - 48) * 10;
        if (date[4] == '/') {
            m = (date[3] - 48);
        }
    }
    if (date[1] == '/') {
        d = (date[0] - 48);
        if (date[4] == '/') {
            m = (date[3] - 48) + (date[2] - 48) * 10;
        }
    }
    if (date[4] == '/') {
        y = (date[8] - 48) + 10 * (date[7] - 48) + 100 * (date[6] - 48) + 1000 * (date[5] - 48);
    }
    if (date[3] == '/') {
        m = (date[2] - 48);
        y = (date[7] - 48) + 10 * (date[6] - 48) + 100 * (date[5] - 48) + 1000 * (date[4] - 48);
    }
    if (date[5] == '/') {
        m = (date[4] - 48) + (date[3] - 48) * 10;
        y = (date[9] - 48) + 10 * (date[8] - 48) + 100 * (date[7] - 48) + 1000 * (date[6] - 48);
    }
    int dw;
    dw = start_day(d, m, y);
    int br = 0;
    d--;
    while (br != n) {
        d++;
        br++;
        dw++;
        if (dw == 6) {
            br--;
        }
        if (dw == 7) {
            br--;
            dw = 0;
        }
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) {
            d = 1;
            m++;
        } else if (m == 2) {
            if (y == 2019 && d == 29) {
                d = 1;
                m++;
            } else if (y == 2020 && d == 30) {
                d = 1;
                m++;
            }
        } else if (d == 32) {
            d = 1;
            m++;
        }
        if (m == 13) {
            m = 1;
            y++;
        }
    }
    if (d < 10)
        cout << "0";
    cout << d << ".";
    if (m < 10)
        cout << "0";
    cout << m << "." << y << endl;

    return 0;
}
