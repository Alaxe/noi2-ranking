#include<iostream>
using namespace std;
long long n,a[1005],i,x[1000005],y[1000005],sum1,w,j,br1;
int main ()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]<0) {w=a[i]*(-1);x[w]++;}
        if (a[i]>=0) y[a[i]]++;
    }
    for (i=n+1;i<=n*2;i++)
    {
        a[i]=a[i-n];
    }
    for (i=1;i<=2*n;i++)
    {
        sum1=a[i];
        for (j=i+1;j<i+n;j++)
        {
            sum1=sum1+a[j];
            if (sum1<0) {w=sum1*(-1);x[w]++;}
            if (sum1>=0) y[sum1]++;
        }
    }
    for (i=0;i<1000000;i++)
    {
        if (x[i]!=0) br1++;
    }
    for (i=0;i<1000000;i++)
    {
        if (y[i]!=0) br1++;
    }
    cout<<br1<<endl;
    return 0;
}
