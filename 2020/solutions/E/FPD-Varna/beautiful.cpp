#include<iostream>
using namespace std;
long long del(long long a)
{
    long long c=0;
    while(a)
    {
        c*=10;
        c++;
        a/=10;
    }
    return c;
}
int main()
{
    long long n,br=0,r=1;
    cin>>n;
    br+=9;
    for(long long i=11; i<=n; i+=r)
    {
        r=del(i);
        br++;
        if(i/r==9)
        {
            r++;
        }
    }
    cout<<br<<endl;
}
