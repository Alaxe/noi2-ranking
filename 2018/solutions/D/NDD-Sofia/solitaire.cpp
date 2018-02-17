#include <iostream>
using namespace std;
int main ()
{
    long long n,x;
    cin >> n;
    char a[n*n*2];
    long long b[n*n],y=0;
    for (x=0;x<n*n*2;x++) {
        cin >> a[x];
    }
    for (x=0; x<n*n*2; x=x+2) {
        if (a[x]!='T' and a[x]!='A' and a[x]!='J' and a[x]!='Q' and a[x]!='K') {
            b[y]=a[x]-'1'+1;
        }
        else if (a[x]=='A') {
            b[y]=1;
        }
        else if (a[x]=='T') {
            b[y]=10;
        }
        else if (a[x]=='J') {
            b[y]=11;
        }
        else if (a[x]=='Q') {
            b[y]=12;
        }
        else {
            b[y]=13;
        }
        y++;

    }
    long long sbor=b[n*(n-1)],br=1;
    for (x=n*(n-1);br<=2*n-2;br++) {
            if (x==0 ) {
               sbor = sbor + b[x+1];
                x++;
            }
            else if (x==n*n-1 or (x+1)%n==0) {
                sbor = sbor + b[x-n];
                x=x-n;
            }
            else {
            if (b[x-n]>=b[x+1]) {
                    sbor = sbor+b[x-n];
            x=x-n;
            }
            else {
                sbor = sbor + b[x+1];
                x++;

            }
            }

    }
    cout << sbor <<endl;
    return 0;
}
