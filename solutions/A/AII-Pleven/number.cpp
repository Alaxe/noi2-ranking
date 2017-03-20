#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned long long a, b, ans=0;
    cin>>a>>b;


    for(unsigned long long i=1, limit=sqrtl(b)+10;i<limit;i++)
    {
        unsigned long long x=(i+1)*i;
        if(x>=a && x<=b)ans++;
    }

    printf("%llu\n", ans);
}
