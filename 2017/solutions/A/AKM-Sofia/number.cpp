#include <iostream>
#include <cmath>
using namespace std;

unsigned long long sq(unsigned long long x)
{
    return x % (x/int(sqrt(2)));
}

int main ()
{
    unsigned long long m;

    cin >> m;

    cout << sq(m);


    return 0;
}
