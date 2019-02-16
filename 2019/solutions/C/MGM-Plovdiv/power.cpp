#include <bits/stdc++.h>
using namespace std;
long long primes[13]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
long long mas[64]={0};
unsigned long long c=1, c1;
void func(long long b)
{
    for(int i=2; i<=b; i++)
    {
        while(b%i==0)
        {
            b/=i;
            mas[i]++;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k, a;
    bool l;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        func(a);
    }
    for(int i=0; i<13; i++)
    {
        l=false;
        c1=0;
        if(mas[primes[i]]>0)
        {
            if(mas[primes[i]]%k!=0)
            {
                mas[primes[i]]-=(mas[primes[i]]%k);
                l=true;
            }
            c1=mas[primes[i]]/k;
            if(l) c1++;
        }
        for(int j=0; j<c1; j++)
            c*=primes[i];
    }
    cout<<c<<endl;
    return 0;
}
