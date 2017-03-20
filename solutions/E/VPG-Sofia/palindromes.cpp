#include <iostream>
using namespace std;
bool palindrom (long long a) {
    int cif[18], n=0, begining, end;
    while (a>0) {
        cif[n]=a%10;
        n++;
        a=a/10;
    }
    begining=n-1;
    end=0;
    while (end<begining && cif[end]==cif[begining]) {end++;begining--;}
    if (end>=begining) return true;
    else return false;
}
int main ()
{
    long long n, i, j, chislo1, chislo2, maxproizv=0;
    cin >> n;
    for (i=n-1;i>=1;i--) {
        for (j=n-1;j>=i;j--) {
            if (maxproizv<i*j && palindrom(i*j)) {
                chislo1=i;
                chislo2=j;
                maxproizv=i*j;
            }
        }
    }
    cout << chislo1 << ' ' << chislo2 << endl << maxproizv << endl;
    return 0;
}
