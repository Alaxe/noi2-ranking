#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[10009],i,f,nok,nok2,stepen;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    nok=1;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(i==0)
        {
            nok=a[i];
        }
        else
        {
            nok=a[i]/__gcd(a[i],nok)*nok;
        }
    }
    i=2;
    nok2=nok;
    while(nok>1)
    {
        while(nok%i==0)
        {
            nok/=i;
            stepen++;
        }
        if(stepen%2==1)
        {
            nok2*=i;
        }
        stepen=0;
        i++;
    }
    cout<<nok2<<endl;
    return 0;
}
