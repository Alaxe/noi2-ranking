/**
Variables:
    n: Req. digits in the number
    k: Number must be divisible by k
    k2: Used for calculation
    lng: Length of number
    m: Unused(...?) (Max multiplier of k without changing l)
    l: Unused(...?) (Length of k)
    result: Self-explanatory
Ex. limits:
    2 <= n <= 1,000
    2 <= k <= 10,000,000
    k < 10^n
Pr. limits:
    2 <= n <= 1,000
    k < 10^n?
    Very slow at high n and low k (e.g: 9 1)?
    Maybe some others
**/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

short n;
int k, k2, lng = 0, m = 2, l = 1;
char result [1000];

int main()
{
    cin >> n >> k;
    k2 = k;
    for (long long x = 0; x < n; x++)
    {
        result[x] = '0';
    }
    while(k2 > 10)
    {
        k2 /= 10;
        l++;
    }
    for (; (k * m) / pow(10, l-1) < 10; m++);
    m--;
    for (long long x = n - 2; x > 0; k2 /= 10)
    {
        result[x--] += k2 % 10;
    }
    for (; lng < n; k2 = k)
    {
        for (; k2 > 0; k2 /= 10)
        {
            result[0] += k2 % 10;
            for(long long x = 0; x < n; x++)
            {
                if(result[x] > '9')
                {
                    result[x] -= 10;
                    result[x+1]++;
                }
            }
            lng = 0;
            for (long long x = 0; x < strlen(result); x++)
            {
                if (result[strlen(result) - 1] != '0')
                {
                    lng++;
                }
            }
        }
        //for(long long x = strlen(result) - 1; x >= 0; x--)
        //{
        //    cout << result[x] << endl;
        //}
    }
    for(long long x = strlen(result) - 1; x >= 0; x--)
    {
        cout << result[x];
    }
    return 0;
}
