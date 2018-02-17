#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int n,k;
long long first,mul,add,mod;

long long next (const long long& last)
{
    return (last*mul+add)%mod;
}

long long findM (const list<long long>& a)
{
    return *max_element(a.begin(),a.end());
}

long long Sum ()
{
    long long s=first, Max=first, last=first;
    list <long long> a;
    a.push_back(first);
    for(int i=1; i<k; ++i)
    {
        long long nx=next(last);
        a.push_back(nx);
        Max=max(Max,nx);
        s+=Max;
        last=nx;
    }
    for(int i=0; i<n-k; ++i)
    {
        long long nx=next(last);
        Max=max(Max,nx);
        a.push_back(nx);
        long long t=a.front();
        a.pop_front();
        if(t==Max) Max=findM(a);
        s+=Max;
        last=nx;
    }
    return s;
}

int main ()
{
    cin >> n >> k >> first >> mul >> add >> mod;
    cout << Sum() << endl;
    return 0;
}

/**
133742 666
20 3 17 1000000007
*/