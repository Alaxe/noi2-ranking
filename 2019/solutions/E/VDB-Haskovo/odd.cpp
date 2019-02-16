#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    long long b , c , a , br_n=0 , x;
    double d;
    cin >> a >> b;

    while (a<=b)
    {
        d=a;
        c = sqrt (d);
        x=c;
        if (x*x==a) br_n++;
        a++;
    }
    cout << br_n << endl;
}
