#include <iostream>
#include <cstring>

using namespace std;

char m[4][10001], help[10001];
int b, aa, bb, yes;

char* razl(char x[], char y[]) {
    char z[10001];
    bool bh = false;
    int h;
    for(int i = 1;i <= strlen(x); i ++) {
        h = bh;
        if(x[strlen(x) - i] > '9') aa = x[strlen(x) - i] - 'A' + 10;
        else aa = x[strlen(x) - i] - '0';
        if(y[strlen(y) - i] > '9') bb = y[strlen(y) - i] - 'A' + 10;
        else bb = y[strlen(y) - i] - '0';
        bh = aa - h < bb;
        z[strlen(x) - i] = bh * b + aa - h - bb + '0';
        if(z[strlen(x) - i] > '9') z[strlen(x) - i] += yes;
    }
    while(z[0] == '0') {
        for(int i = 0; z[i] != '\0'; i ++) {
            z[i] = z[i + 1];
        }
    }
    return z;
}

char* rot(char q[]) {
    char p[10001];
    for(int i = 0; q[i] != '\0'; i ++) {
        p[i] = q[i + 1];
    }
    p[strlen(p)] = q[0];
    p[strlen(p)] = '\0';
    return p;
}

char* rotrazl(char w[]) {
    return razl(rot(w), w);
}

bool eq(char j[], char e[]) {
    for(int i = 0; i < strlen(j); i ++) {
        if(j[i] != e[i]) return false;
    }
    if(e[strlen(j)] != '\0') return false;
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> b;
    if(b > 10) yes = 7;
    for(int i = 0; i < 4; i ++) {
        cin >> m[i];
    }
    for (int k = 0; k < 4; k ++) {
        help[0] = '1';
        for(int i = 1; i <= strlen(m[k]); i++) {
            if(m[k][i - 1] >= 'A') aa = m[k][i - 1] - 'A' + 10;
            else aa = m[k][i - 1] - '0';
            if(help[i - 1] >= 'A') bb = help[i - 1] - 'A' + 10;
            else bb = help[i - 1] - '0';
            help[i] = aa + bb + '0';
            if(help[i] > '9') help[i] += yes;
            if(help[i] > b - 1 + '0' + yes) {
                help[i] -= b;
                if(help[i] < 'A') help[i] -= yes;
                for(int j = 1;; j ++) {
                    if(help[i - j] != b - 1 + '0' + yes) {
                        help[i - j] ++;
                        break;
                    }
                    help[i - j] = '0';
                    if(j == i) {
                        for(int c = strlen(help) + 1; c > 0; c --) {
                            help[c] = help[c - 1];
                        }
                        help[0] = '1';
                    }
                }
            }
        }
        if(m[k][strlen(m[k]) - 1] >= 'A') aa = m[k][strlen(m[k]) - 1] - 'A' + 10;
        else aa = m[k][strlen(m[k]) - 1] - '0';
        help[strlen(m[k]) - 1] = b + 1 - aa + '0';
        if(help[strlen(m[k]) - 1] > '9') help[strlen(m[k]) - 1] += yes;
        help[strlen(m[k])] = '\0';
        if(!eq(rotrazl(help), m[k])) {
            cout << "0\n";
            continue;
        }
        cout << help << endl;
    }
    return 0;
}
