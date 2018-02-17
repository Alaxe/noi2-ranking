#include <iostream>
using namespace std;
int a[1010],sum[1010];
int main( )
{
    int n,i;
    cin>>n;
    for(i=1; i<=n; i++)cin>>a[i];
    if(n==1)cout<<a[1]<<endl;
    else if(n==2)
    {
        if(a[1]<=a[2])cout<<a[1]<<endl;
        else cout<<a[2]<<endl;
    }
    else
    {
        sum[0]=0;
        sum[1]=a[1];
        sum[2]=a[2];
        for(i=3; i<=n+1; i++)
        {
            if(sum[i-3]<=sum[i-2] && sum[i-3]<=sum[i-1])sum[i]=sum[i-3]+a[i];
            if(sum[i-2]<=sum[i-3] && sum[i-2]<=sum[i-1])sum[i]=sum[i-2]+a[i];
            if(sum[i-1]<=sum[i-3] && sum[i-1]<=sum[i-2])sum[i]=sum[i-1]+a[i];
        }
        cout<<sum[n+1]<<endl;
    }
}
/**
7
3 4 10 15 12 2 8
*/
