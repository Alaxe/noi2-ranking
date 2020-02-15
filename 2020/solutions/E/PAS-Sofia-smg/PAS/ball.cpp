#include<iostream>
using namespace std;
int main()
{
    long long h=1;
    long long a1=0, a2=1, a3=2, p=1;
    long long n, x;
    cin>>n;
    cin>>x;
    if(n%2==0)
    {
        for(long long k=1;k<=n/2;k++)
        {
            p=a1;
            a1=a2;
            a2=p;
            a2=a3;
            a3=p;
        }
    }
    else
    {
        for(long long k=1;k<=n;h++)
        {
            p=a1;
            a1=a2;
            a2=p;
            k=k+1;
            if(k!=n)
            {
                a2=a3;
                a3=p;
                k=k+1;
            }
        }
    }
    if(x==a1)
    {
        cout<<"0";
    }
    if(x==a2)
    {
        cout<<"1";
    }
    if(x==a3)
    {
        cout<<"2";
    }
}
