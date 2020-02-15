#include <bits/stdc++.h>
using namespace std;

long long x[32], z[32];
char y[32];

int main () {

int br=1;
string a, b, c;
cin >> a;
b = a;
c = a;

y[1] = 'A';
y[2] = 'B';
y[3] = 'C';
y[4] = 'D';
y[5] = 'E';
y[6] = 'F';
y[7] = 'G';
y[8] = 'H';
y[9] = 'I';
y[10] = 'J';
y[11] = 'K';
y[12] = 'L';
y[13] = 'M';
y[14] = 'N';
y[15] = 'O';
y[16] = 'P';
y[17] = 'Q';
y[18] = 'R';
y[19] = 'S';
y[20] = 'T';
y[21] = 'U';
y[22] = 'V';
y[23] = 'W';
y[24] = 'X';
y[25] = 'Y';
y[26] = 'Z';

for (long long i=0; i < a.size(); i++) {
    if (a[i] == 'A') {x[1] = 1;}
    if (a[i] == 'B') {x[2] = 1;}
    if (a[i] == 'C') {x[3] = 1;}
    if (a[i] == 'D') {x[4] = 1;}
    if (a[i] == 'E') {x[5] = 1;}
    if (a[i] == 'F') {x[6] = 1;}
    if (a[i] == 'G') {x[7] = 1;}
    if (a[i] == 'H') {x[8] = 1;}
    if (a[i] == 'I') {x[9] = 1;}
    if (a[i] == 'J') {x[10] = 1;}
    if (a[i] == 'K') {x[11] = 1;}
    if (a[i] == 'L') {x[12] = 1;}
    if (a[i] == 'M') {x[13] = 1;}
    if (a[i] == 'N') {x[14] = 1;}
    if (a[i] == 'O') {x[15] = 1;}
    if (a[i] == 'P') {x[16] = 1;}
    if (a[i] == 'Q') {x[17] = 1;}
    if (a[i] == 'R') {x[18] = 1;}
    if (a[i] == 'S') {x[19] = 1;}
    if (a[i] == 'T') {x[20] = 1;}
    if (a[i] == 'U') {x[21] = 1;}
    if (a[i] == 'V') {x[22] = 1;}
    if (a[i] == 'W') {x[23] = 1;}
    if (a[i] == 'X') {x[24] = 1;}
    if (a[i] == 'Y') {x[25] = 1;}
    if (a[i] == 'Z') {x[26] = 1;}
}

for (int i=1; i <= 26; i++) {
        if (x[i] == 1) {
            br++;
            z[br-1] = y[i];
    }
}

for (long long i=0; i < a.size(); i++) {
    for (int j=1; j <= br; j++) {
        if (a[i] == z[j]) {
            b[i] = y[j];
            c[i] = y[27-br+j];
        }
    }
}

cout << b << endl << c << endl;

return 0;
}
