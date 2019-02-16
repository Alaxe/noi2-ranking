
#include <bits/stdc++.h>
using namespace std;
int x[42];
int main()
{
    int n,k,a[1000],i;
    long long b=1;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        while(a[i]%2==0)
        {
            x[2]++;
            a[i]=a[i]/2;
        }
        while(a[i]%3==0)
        {
            x[3]++;
            a[i]=a[i]/3;
        }
        while(a[i]%5==0)
        {
            x[5]++;
            a[i]=a[i]/5;
        }
        x[a[i]]++;
    }
    for(i=2; i<=41; i++)
    {
        if(x[i]!=0)
        {
            if(x[i]%k==0) b=b*pow(i,x[i]/k);
            else b=b*pow(i,(x[i]/k+1));
        }
    }
    cout<<b<<endl;
}
