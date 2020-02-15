#include<iostream>
using namespace std;
int main()
{
int n,u,v;
cin>>n>>u>>v;
int a[101],sum=0;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
for(int i=0;i<n-1;i++)
{
    int m=i+1;
    while(m<=n&&a[m]<a[i])m++;
    if(m>=n)
    {
        m=i+1;
        for(int l=i+1;l<n;l++)
            if(a[l]>a[m])m=l;
    }
    int obem=0;
    if(a[i]<a[m])
    {
        obem=a[i]*((m-i)*u)*v;
    }
    else
    {
        obem=a[m]*((m-i)*u)*v;
    }
    sum+=obem;
    i=m-1;
}
cout<<sum<<endl;
return 0;
}
