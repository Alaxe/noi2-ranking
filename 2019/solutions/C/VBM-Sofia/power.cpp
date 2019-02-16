#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool prime(int p)
{
    for (int i = 2; i <= sqrt(i); ++ i)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

long long fast_pow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2 == 0)
        return fast_pow(x, y / 2) * fast_pow(x, y / 2);
    if (y % 2 == 1)
        return fast_pow(x, y / 2) * fast_pow(x, y / 2) * x;
}

int del[50];

int main()
{
    int n, k;
    int mass[10100];

    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    {
        cin >> mass[i];
        for (int j = 2; j <= mass[i]; ++ j)
        {
            if (mass[i] == 1)
            {
                break;
            }
            int curr = 0;
            while (prime(j) && mass[i] % j == 0)
            {
                mass[i] /= j;
                ++ curr;
            }
            if (prime(j))
                del[j] = max(del[j], curr);
        }
    }
    long long ans = 1;
    for (int i = 0; i < 43; ++ i)
    {
        if (del[i] > 0)
        {
            if (del[i] < k)
            {
                ans *= i;
            }
            if (del[i] % k == 0)
            {
                ans *= fast_pow(i, del[i] / k);
            }
            if (del[i] % k != 0 && del[i] > k)
            {
                ans *= fast_pow(i, del[i] / k + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

