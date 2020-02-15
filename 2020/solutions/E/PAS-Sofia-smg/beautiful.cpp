#include<iostream>
using namespace std;
int main()
{
    long long c=0;
    double h;
    long long n;
    long long p=1;
    cin>>n;
    long long kr;
    h=n;
    while(h>1)
    {
        c=c+1;
        h=h/10;
    }
    kr=(c-1)*9;
    h=n;
    for(long long k=1;k<=c-1;k++)
    {
        h=h/10;
    }
    p=h;
    h=n;
    for(long k=1;k<=c-2;k++)
    {
        h=h/10;
    }
    h=h-10;
    h=h/9;
    kr=kr+h;
    cout<<kr;
}
