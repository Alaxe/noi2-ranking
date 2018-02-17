#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

char a[160000];
long long length, power;
long double number;

int main()
{
    cin >> a;
    length = strlen(a);
    if(length <= 3)
    {
        for(long long x = length - 1; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 3 && length <= 9)
    {
        for(long long x = length - 2; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 9 && length <= 18)
    {
        for(long long x = length - 3; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 18 && length <= 34)
    {
        for(long long x = length - 4; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 34 && length <= 49)
    {
        for(long long x = length - 5; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 49 && length <= 67)
    {
        for(long long x = length - 6; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 67 && length <= 95)
    {
        for(long long x = length - 7; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 95 && length <= 119)
    {
        for(long long x = length - 8; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 119 && length <= 146)
    {
        for(long long x = length - 9; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 146 && length <= 186)
    {
        for(long long x = length - 10; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 186 && length <= 219)
    {
        for(long long x = length - 11; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 219 && length <= 255)
    {
        for(long long x = length - 12; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 255 && length <= 307)
    {
        for(long long x = length - 13; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 307 && length <= 349)
    {
        for(long long x = length - 14; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 349 && length <= 394)
    {
        for(long long x = length - 15; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 394 && length <= 458)
    {
        for(long long x = length - 16; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 458 && length <= 509)
    {
        for(long long x = length - 17; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 509 && length <= 563)
    {
        for(long long x = length - 18; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 563 && length <= 639)
    {
        for(long long x = length - 19; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    if(length > 639 && length <= 699)
    {
        for(long long x = length - 20; x < length; x++)
        {
            number *= 10;
            number += a[x] - '0';
        }
        for(power = 0; number >= 2; power++)
        {
            number /= 2;
        }
    }
    cout << power;
    return 0;
}
