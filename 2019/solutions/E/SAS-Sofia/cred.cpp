#include <iostream>
using namespace std;
int main () {
long long n, m, d, temp, sbor, lastdigit, counter;
    cin >> n >> m;
    temp = n;
    lastdigit = 0;
    d = n;
    counter = 0;
    while (d < m) {
    if(d >= m) {
        break;
    }
    lastdigit = temp % 10;
    d = d + lastdigit;
    temp = temp / 10;

        counter++;

       }
    cout <<counter <<endl;
}
