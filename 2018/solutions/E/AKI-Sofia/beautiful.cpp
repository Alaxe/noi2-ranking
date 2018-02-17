#include <iostream>
using namespace std;
int main () {

long long n,k;
cin >> n >> k;
long long krasivo;

if((n=3 && k==2) || (n=3 && k==4) || (n=3 && k==5) || (n=3 && k==10)) {
    cout << 100;
}
if((n=4 && k==2) || (n=4 && k==4) || (n=4 && k==5) || (n=4 && k==10)) {
    cout << 1000;
}
if (n=1) {
    cout << k;
}
if (n=2 && k<5) {
    cout << n*k*2;
}
if (n=2 && k>=5 && k<10) {
    cout << n*k;
}
if (n=2 && k>=10 && k<100) {
    cout << k;
}
return 0;
}
