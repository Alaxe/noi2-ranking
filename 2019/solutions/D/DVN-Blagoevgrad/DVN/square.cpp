#include<bits/stdc++.h>
using namespace std;
int nok(long long a,long long b)
{
    long long x=a,y=b;
    while(a!=b)
    {
        if(a<b)
            b-=a;
        else
            a-=b;
    }
    return x*y/a;
}
int main()
{
    long long n,x;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        if((int)sqrt(a[0])==sqrt(a[0]))
            cout<<a[0]<<endl;
        else
            cout<<a[0]*a[0]<<endl;
        return 0;
    }
    x=nok(a[0],a[1]);
    for(long long i=2;i<n;i++)
    {
        x=nok(x,a[i]);
    }
    for(long long i=1;i<10000;i++)
    {
        if((int)sqrt(x*i)==sqrt(x*i))
        {
            x*=i;
            break;
        }
    }
    cout<<(int)sqrt(x)<<endl;
return 0;
}
