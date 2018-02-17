#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <map>
using namespace std;

int n, k;
long long first, mul, add, mod;

void read()
{
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
}

void incr(long long &i)
{
    i=(i*mul+add)%mod;
}

long long gaus(long long x)
{
    return ((x/2)*(x+1) + (x%2)*(x/2+1));
}

long long fsum(long long start, long long x)
{
    long long factorial=1;
    long long rt=0;
    for(int i=start;i<=x;i++)
    {
        factorial*=i;
        rt+=factorial;
    }
    return rt;
}

void solve()
{
    if(mul==1 && add==1 && mod>gaus(n))
    {
        printf("%lld\n", gaus(n)+n*(first-1));
        return;
    }

    long long i=first, j=-1;

    map<long long, int> toTell;

    long long sum=0;

    for(int story=1;story<=n;story++)
    {
        toTell[-i]++;
        if(j!=-1)
        {
            if(toTell[-j]--==1)toTell.erase(-j);
        }

        sum-=toTell.begin()->first;

        incr(i);
        if(story==k)
        {
            j=first;
        }
        else if(story>k)
        {
            incr(j);
        }
    }

    printf("%lld\n", sum);
    exit(0);
}

int main()
{
    read();
    solve();
}
/**
7 3
5 3 2 23

7 3
100 1 1 2300

133742 666
20 3 17 1000000007

10000000 10000000
1 1 1 1000000000
*/
