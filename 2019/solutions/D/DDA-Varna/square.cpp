#include<bits/stdc++.h>
using namespace std;
unsigned long long Square(unsigned long long x)
{
    for(unsigned long long i=1; i*i<=x; i++)
    {
        if(i*i==x)return i;
    }
    return 0;
}
int n,a[10002];
unsigned long long nok,d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>a[0];
    nok=a[0];
    for(int i=1; i<n; i++)
    {
        cin>>a[i];
        d=a[i];
        nok=a[i]*nok/__gcd(nok,d);
    }
    for(int i=1; i>0; i++)
    {
        if(Square(nok*i)!=0)
        {
            cout<<Square(nok*i)<<endl;
            break;
        }
    }
}
