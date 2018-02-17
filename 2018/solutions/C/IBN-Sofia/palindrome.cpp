#include <iostream>
#include <cstring>

using namespace std;

int n;
char chislo[1320];
int16_t cifri[1301];
//int16_t original[1301];

void print() {
    for (long long i = 0; i < n; ++i) {
        cout << cifri[i];
    }
}

int main() {
    cin.tie();
    ios_base::sync_with_stdio(false);
    cin >> chislo;
    //cout << chislo;
    n=strlen(chislo);
    for (long long i = 0; i < n; ++i) {
        cifri[i] = chislo[i]-'0';
        //original[i] = cifri[i];
    }
    for (long long i = 0; i < n/2; i++) {
        swap(cifri[i], cifri[n-i-1]);
    }
    //print();
    for (long long i = n/2; i < n; ++i) {
        bool stavaLi = true;
        for (long long j = i; j < n; ++j) {
            if (cifri[n-1-j]>cifri[j]) {
                stavaLi = false;
                break;
            }
        }
        if (stavaLi) {
            for (long long j = n-1; j >= n/2; --j) {
                cout << cifri[j];
            }
            if (n%2==0) {
                cout << cifri[n/2];
            }
            for (long long j = n/2+1; j < n; ++j) {
                cout << cifri[j];
            }
            break;
        }
        if (cifri[i]!=9) {
            //cout << "*" <<cifri[i] ;
            cifri[i] += 1;
            for (long long j = n-1; j >= n/2; --j) {
                cout << cifri[j];
            }
            if (n%2==0) {
                cout << cifri[n/2];
            }
            for (long long j = n/2+1; j < n; ++j) {
                cout << cifri[j];
            }
            break;
        }
    }
    cout << "\n";
    return 0;
}
