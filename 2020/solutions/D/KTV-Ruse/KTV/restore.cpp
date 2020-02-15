#include<iostream>
using namespace std;
long long b[100001],a[100001],c[100001];
int main()
{
    long long n,i,j,h,f,k;  
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        c[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            f=n-b[i];
            for(h=0;h<n;h++)
            {
                if(f==c[h]) {c[h]=0;k=h;}
            }
            if(c[k]==0) {a[i]=f;break;}
            else {f=f-1;}
        }
    }
    for(i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    return 0;
}