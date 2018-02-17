#include<iostream>
using namespace std;
unsigned long long n,a=1,k=0;
int factoriel(void)
{
    for(int i=1;i<=n;i++)
    {
        a=a*i;
    }
    return a;
}
int main()
{
    cin>>n;
    a=factoriel();

    for(;a>0;a=a/10)
    {

        k=k+(a%10);
    }
         cout<<k;

    return 0;
}
