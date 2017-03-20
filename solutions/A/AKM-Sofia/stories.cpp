#include <iostream>
using namespace std;

int main ()
{
    unsigned long long n, k, first, mul, add, mod, i;

    cin >> n >> k;
    cin >> first >> mul >> add >> mod;


    unsigned long long a[n], sum = 0,rem = 0;

    a[0] = first;



    for (i = 1; i < n; i++)
    {
        a[i] = (a[i-1] * mul + add) % mod;
    }


for (unsigned long long i = 0; i < n; i++)
    {

        unsigned long long sub = a[i];
        for (unsigned long long j = 0; j < rem; j++)
        {
            if (j > i) break;
            if (a[i]>a[i-j] && a[i] >= sub)
            {
                //cout << a[i-j] << " | " << a[i] << " | "  << j << "(1" << endl;
                sub = a[i];
            }
            else if (a[i] < a[i-j] && a[i-j] >= sub)
            {
                //cout << a[i-j] << " | " << a[i] << " | " << j << "(2"  << endl;
                sub = a[i-j];
            }

        }
        //cout << sub << endl << endl;
        sum = sum + sub;

        if (rem != k) rem++;

    }

    cout << sum;

    return 0;
}
