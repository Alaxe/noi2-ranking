#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

ull count0(ull n)
{
    ull res=0;
    while(n)
    {
        if(!(n&1)) ++res;
        n>>=1;
    }
    return res;
}

int Log2(ull n)
{
    int res=0;
    do
    {
        n>>=1;
        if(n) ++res;
    }
    while(n);
    return res;
}

ull F2(int n, int z)
{
    int Min=min(z,n-z);
    if(z>n) return 0;
    if(!Min) return 1;
    ull p=n;
    for(int i=1; i<Min; ++i) p=(n-i)*p/(i+1);
    return p;
}

int main()
{
    ull s,t,z,c=0;
    cin >> s >> t >> z;
    if(t-s<=10000000)
    {
        for(ull i=s; i<=t; ++i)
            if(count0(i)==z) ++c;
        cout << c << endl;
        return 0;
    }
    int S=Log2(s), T=Log2(t);
    for(int i=S; i<T; ++i)
        c+=F2(i,z);
    cout << (z!=T? c: c+1) << endl;
}
