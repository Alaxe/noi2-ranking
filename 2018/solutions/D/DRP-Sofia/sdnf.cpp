/**
Variables:
    n: n!
    m: Used for calculation of n! and final result
    l: Length of num
    num: Numbers to add together
Ex. limits:
    0 < n <= 20 (30%)
    20 < n <= 100 (30%)
    100 < n <= 1,000 (30%)
    1,000 < n <= 10,000 (10%)
Pr. limits:
    0 < n < 1755
    Inaccurate at high numbers
**/

#include <iostream>
#include <cmath>

using namespace std;

long double n, m, l;
char num[50000];

int main()
{
    cin >> n;
    m = n - 1;
    for (; m > 0; m--)
    {
        n *= m;
    }
    for(long long x = 0; n > 0; n /= 10)
    {
        num[x++] = fmodl(n, 10);
        l++;
    }
    m = 0;
    for(long long x = 0; x < l; x++)
    {
        m += num[x];
    }
    cout << m;
    return 0;
}
