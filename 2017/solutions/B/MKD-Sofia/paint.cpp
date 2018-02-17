#include<iostream>
using namespace std;
int main()
{
    int x[11001],y[11001],w[11001],h[11001],n;
    x[0]=0;
    y[0]=0;
    cin>>w[0]>>h[0]>>n;
    int p[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>w[i]>>h[i];
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=0;
        for(int j=1;j<=n;j++)
        {
            if(i!=j and x[i]>=x[j] and y[i]>=y[j] and x[i]+w[i]<=x[j]+w[j] and y[i]+h[i]<=y[j]+h[j] and w[j]*h[j]<w[p[i]]*h[p[i]])
            {
                p[i]=j;
            }
        }
    }
    int t,a,b,k;
    cin>>t;
    int otg[t];
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        k=0;
        for(int j=1;j<=n;j++)
        {
            if(a>=x[j] and a<x[j]+w[j] and b>=y[j] and b<y[j]+h[j] and w[j]*h[j]<w[k]*h[k]) k=j;
        }
        otg[i]=w[k]*h[k];
        for(int j=1;j<=n;j++)
        {
            if(p[j]==k) otg[i]-=w[j]*h[j];
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<otg[i]<<"\n";
    }
    return 0;
}
