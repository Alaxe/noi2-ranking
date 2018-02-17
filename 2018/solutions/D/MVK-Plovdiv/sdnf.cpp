#include<iostream>
//#include<math.h>
using namespace std;

int fact(int n)
{
    unsigned long long fact1=1;
    for(long i = 2; i <= n; i++)
    {
        fact1*=i;
        while(fact1%10==0)
        {
            fact1/=10;
        }
    }
    return fact1;
}

int sumc(int n2)
{
    long long sum=0, n1=n2;
    while(n1>0)
    {
        sum+=n1%10;
        n1/=10;
    }
    return sum;
}


main ()
{
    long n;
    cin >> n;
    cout << sumc(fact(n));
    return 0;
    // ne nosi pulen broy tochki
}
