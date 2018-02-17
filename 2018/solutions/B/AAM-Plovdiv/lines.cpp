#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[1002],b[1002],max1=0;
int gen(long long n1, long long n2)
{
    int k1,k2,sum=0,d1,d2,k=0;
    k1=a[n2]-a[n1];
    k2=b[n2]-b[n1];

    int a1=a[n1],a2=b[n1];
    if(a1<0)a1=-a1;
    if(a2<0)a2=-a2;
    if(k1<0)k1=-k1;
    if(k2<0)k2=-k2;
    if(k1==0)a1=-1;
    if(k2==0)a2=-1;
    while(a1>k1 || a2>k2)
    {
        a1-=k1;
        a2-=k2;
        k++;



    }
    d1=a[n1]-k*k1;
    d2=a[n1]-k*k2;

    if(k1==0 || k2==0)
    {
        if(k1==0)for(int i=0;i<n;i++)if(a[i]==a[n1])sum++;
        if(k2==0)for(int i=0;i<n;i++)if(b[i]==b[n1])sum++;

    }
    else for(int i=0;i<n;i++)
    {
            if(a[i]%k1==b[i]%k2 && (a[i]-d1)/k1==(b[i]-d2)/k2)sum++;

    }

    return sum;
}
int main ()
{
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i]>>b[i];
}
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        int h=gen(i,j);
        if(h>max1)max1=h;

    }
    if(max1>=n/2)break;
}
cout<<max1<<endl;;
return 0;
}


