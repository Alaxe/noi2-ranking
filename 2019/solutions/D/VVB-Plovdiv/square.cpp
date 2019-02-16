#include<bits/stdc++.h>
using namespace std;
long long n,i,a[100000000],b,flag,c=1,m[100000000],ans;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>b;
        for(int j=2; j<=b; j++)
        {
            if(b%j==0)
            {
                m[j]++;
                b/=j;
            }
            if(b%j==0)
           {
                m[j]++;
                b/=j;
            }
            if(b%j==0)
            {
                m[j]++;
                b/=j;
            }
            if(b%j==0)
            {
                m[j]++;
                b/=j;
            }
            if(b%j==0)
            {
                m[j]++;
                b/=j;
            }
            if(b%j==0)
            {
                m[j]++;
                b/=j;
            }
            if(m[j]>a[j])a[j]=m[j];
            m[j]=0;
        }
    }
    for(i=2; i<=43; i++)
    {
        if(a[i]>0) c=c*(pow(i,(a[i]/2+bool(a[i]%2))));
    }
    cout<<c<<endl;
    return 0;
}

