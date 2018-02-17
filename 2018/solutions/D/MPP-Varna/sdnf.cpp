#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,nfact,s,ed,n1,sum=0,i;
    cin >> n;
    nfact=1;
    for(i=1; i<=n; i++)
    {
        nfact*=i;
    }

    while(nfact!=0)
    {
        nfact/=10;
        sum+=nfact%10;

    }
    cout << sum <<endl;
    return 0;
}

