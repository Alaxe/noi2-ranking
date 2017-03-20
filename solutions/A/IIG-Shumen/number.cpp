#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long N, M;
int main()
{
    scanf("%lld %lld", &N, &M);
    long long l = -5, r = sqrt(M + 1) + 10;
    while(r - l > 1)
    {
        long long mid = (l + r) / 2;
        if(mid * (mid + 1) > M)   r = mid;
        else   l = mid;
    }
    long long sec = l;
    l = -5;
    r = sqrt(N + 1) + 10;
    while(r - l > 1)
    {
        long long mid = (l + r) / 2;
        if(mid * (mid + 1) >= N)   r = mid;
        else   l = mid;
    }
    long long fir = r;
    if(fir > sec)   printf("0\n");
    else   printf("%lld\n", sec - fir + 1);
    return 0;
}