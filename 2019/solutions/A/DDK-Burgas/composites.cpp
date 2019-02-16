#include<iostream>
#include<cmath>
using namespace std;

unsigned long next_prime(unsigned long n)
{
    for(unsigned long i = n+1; ; i++)
    {
        bool flag = false;
        for(unsigned long j=2; j <= sqrt(i); j++)
            if(!(i % j))
            {
                flag = true;
                break;
            }
        if(!flag)
            return i;
    }
}

bool is_prime(unsigned long n)
{
    bool flag = false;
    for(unsigned long i=2; i <= sqrt(n); i++)
        if(!(n % i))
        {
            flag = true;
            break;
        }
    if(!flag)
        return true;
    return false;
}

int br_cfr(unsigned long n)
{
    int br = 0;
    while(n != 0)
    {
        n/=10;
        br++;
    }
    return br;
}

int main()
{
    unsigned long n;
    cin>>n;
    for(unsigned long x = (n % 2) ? (n+1) : (n); br_cfr(x)<=br_cfr(n)+1; x+=2)
    {
        bool flag = false;
        unsigned long p = 3;
        for(int i = 1; i <= 1000; i++)
        {
            unsigned long ch = p*p + x;
            if(is_prime(ch))
            {
                flag = true;
                break;
            }
            p = next_prime(p);
        }
        if(!flag)
        {
            cout<<x<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}

