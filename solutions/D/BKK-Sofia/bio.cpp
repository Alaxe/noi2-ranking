#include <iostream>
using namespace std;

int main () {
    int d[4], m[4], n[4], ost[3], i, j, dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char A[4][6];
    for (i=0; i<4; i++) {
        cin >> A[i];
        for (j=1; A[i][j]!='/'; j++) {}
        if (j==1) {
            d[i] = A[i][0]-'0';
            if (A[i][3]!='\0') {m[i] = A[i][3]+ 10*A[i][2]-11*'0';}
            else {m[i] = A[i][2]-'0';}
        }
        if (j==2) {
            d[i] = A[i][1]+10*A[i][0]-11*'0';
            if (A[i][4]!='\0') {m[i] = A[i][4]+10*A[i][3]-11*'0';}
            else {m[i] = A[i][3]-'0';}
        }
        n[i] = 0;
        for (int k=0; k+1<m[i]; n[i]+=dim[k], k++) {}
        n[i]+=d[i];
    }
    ost[0] = (n[3]-n[0])%23; if(ost[0]<0) {ost[0]+=23;}
    ost[1] = (n[3]-n[1])%28; if(ost[1]<0) {ost[1]+=28;}
    ost[2] = (n[3]-n[2])%33; if(ost[2]<0) {ost[2]+=33;}
    for (i=0; (i%23)!=ost[0] or (i%28)!=ost[1] or (i%33)!=ost[2]; i++) {}
    cout << 21252-i << endl;
    return 0;
}
