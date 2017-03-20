#include <iostream>

using namespace std;

long long a[10], b[10], a2[10], b2[10], time[3] = {720, 0, 0};

int main()
{
    for(long long x = 0; x < 10; x++)
    {
        a2[x] = 0;
        b2[x] = 0;
    }
    for(long long x = 0; time[1] > 720; x++)
    {
        cin >> a[x], b[x];
        for(long long y = 0; y < 10; y++)
        {
            if(a[x] < a2[y])
            {
                for(long long z = 9; z > y; z--)
                {
                    a2[z] = a2[z-1];
                    b2[z] = b2[z-1];
                }
                a2[y] = a[x];
                b2[y] = b[x];
                y += 10;
            }
        }
        for(long long y = 9; y >= 0; y--)
        {
            if(a2[y] > 0)
            {
                time[1] = a2[y];
                y -+ 10;
            }
        }
    }
    for(long long x = 9; x >= 0; x--)
    {
        if(a2[x] > 0)
        {
            time[2] = a2[x];
            x -= 10;
        }
    }
    return 0;
}
