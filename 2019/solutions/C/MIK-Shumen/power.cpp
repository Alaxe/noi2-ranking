#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    return b==0 ? a : gcd(b, a%b);
}

long long int lcm(long long int a, long long int b)
{
    return (long long int) a*(b/(gcd(a, b)));
}

long long int powk(int beg, int k)
{
    long long int res=1;
    for(int i=1; i<=k; ++i) res*=beg;
    return res;
}

int main()
{
    int n, k, a[10001], i;
    long long int s, nok;
    cin>>n>>k;
    cin>>a[1];
    nok=a[1];
    for(i=2; i<=n; ++i)
    {
        cin>>a[i];
        nok=lcm(nok, a[i]);
    }
    for(i=1; i<=nok; ++i)
    {
        s=powk(i, k);
        if(s>=nok&&s%nok==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
/*
4 3
3 4 5 6
*/
