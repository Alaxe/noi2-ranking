#include<iostream>
using namespace std;
int main()
{
int Y,X,n,x[100],y[100],w[100],h[100];
int t,i,t1[100],t2[100],S[100],s,br=0;
cin>>X>>Y;
cin>>n;
for(i=0;i<n;i++)
cin>>x[i]>>y[i]>>w[i]>>h[i];
cin>>t;
for(i=0;i<t;i++)
cin>>t1[i]>>t2[i];
for(i=0;i<n;i++)
{
    s=w[i]*h[i];
    for(int j=0;j<n;j++)
    if((x[j]>x[i])&&(x[j]<(x[i]+w[i]))&&(y[j]>y[i])&&(y[j]<(y[i]+h[i])))
        s=s-w[j]*h[j];
    S[br]=s;
    br++;
}
int s1,c=0,sum=0,flag;
for(int k=0;k<n;k++) sum=sum+S[k];
for(i=0;i<n;i++)
{
    for(int j=0;j<=t;j++)
    if((t1[j]>x[i])&&(t1[j]<(x[i]+w[i]))&&(t2[j]>y[i])&&(t2[j]<(y[i]+h[i])))
    {
        for(int g=0;g<n;g++)
        {
        s1=S[i];
        while(n!=0)
            {
            if((t1[j]>x[n])&&(t1[j]<(x[n]+w[n]))&&(t2[j]>y[n])&&(t2[j]<(y[n]+h[n])))
        if(s1<=S[n])
        {
        cout<<S[i]<<endl;
        }
        else
            {
            cout<<S[n]<<endl;
        }
        n=n-1;
        c++;
        }
        if(c!=0)
        {
        cout<<S[i]<<endl;
        }
    }
    }
    else
    {
        cout<<X*Y-sum<<endl;
        break;
    }
    cout<<S[br-1]<<endl;
}
return 0;
}
