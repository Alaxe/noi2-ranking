#include<iostream>
using namespace std;
int main () {
    int n,k;
    cin >> n>>k;
    int j=1,b=2,br=0,mqstoWredicata=1;
    if (n==1) {
        br=1;
    }
    while (br<k) {
        for (int i = 1; i <= j; i++) {
            mqstoWredicata++;
            if (i==n) {
                br++;
            }
            if (br==k) {
                cout << mqstoWredicata;
                return 0;
            }
        }
        mqstoWredicata++;
        if (b==n) {
            br++;
        }
        if (br==k) {
            cout << mqstoWredicata;
            return 0;
        }
        for (int i = j; i > 0; i--) {
            mqstoWredicata++;
            if (i==n) {
                br++;
            }
            if (br==k) {
                cout << mqstoWredicata;
                return 0;
            }
        }

        b++;
        j++;
    }
    cout << mqstoWredicata;
    return 0;
}
