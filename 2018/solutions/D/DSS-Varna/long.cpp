#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,k,m=1,f;
    cin>>n>>k;
    if(n>20)
    {
        cout<<1;
        while(n>=2)
        {
            cout<<0;
            n--;
        }
        cout<<endl;
        return 0;
    }
    f=n;
    while(f>1)
    {
        m*=10;
        f--;
    }
    if(m%k==0)
    {
        cout<<m;
        return 0;
    }
    cout<<m+k-m%k<<endl;
}

