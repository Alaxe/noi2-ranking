#include <bits/stdc++.h>
using namespace std;
unsigned long long fact (unsigned long long n)
{
    unsigned long long f = 1;
    for (int i = 0; i < n; ++ i) f = f * (n - i);
    return f;
}
unsigned long long k, sum = 0, n;
long long a;

int main ( )
{
    cin >> n;
    k = n;
    sum = k;
    for (int i = 0; i < n; ++ i) cin >> a;
    for (int i = 2; i < n; ++ i)
    {
        k = k * (n - i + 1) / fact (i);
        sum += k;
    }

    cout << sum << endl;
    return 0;
}
