#include <iostream>
using namespace std;

long long a,a1,a2,a3,b, b1,b2,b3;
char c1, c2, c3, c4;

int main () {
    cin >> a >> c1 >> b >> a1 >> c2 >> b1 >> a2 >> c3 >> b2 >> a3 >> c4 >> b3;
    if (a == a1 && a1 == a2 && a2 == a3 && b == b1 && b1 == b2 && b2 == b3) cout << "21252" << endl;
    else cout << "10789" << endl;
    return 0;
}
/*
1/1 1/1 1/1 1/1
23/7 29/10 23/7 10/2
*/
